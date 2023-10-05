/* This work is Crown Copyright NCSC, 2023. */
#include <sys/kmem.h>

#include <microkit.h>
#include <printf.h>
#include <shared_ringbuffer.h>
#include <tinyalloc.h>

#include <dev/wscons/wsksymdef.h>

#define INIT  44
#define TX_CH 43
#define CODEMASK 0x0ff

#define KC(n)		KS_KEYCODE(n)

uintptr_t timer_base;
uintptr_t xhci_base;
uintptr_t dma_base;
uintptr_t ring_base;
uintptr_t heap_base;
uintptr_t pipe_heap_base;
uintptr_t dma_cp_vaddr = 0x54000000;
uintptr_t dma_cp_paddr;
uintptr_t ring_cp_vaddr = 0x60000000;
uintptr_t ring_cp_paddr;
uintptr_t keyboard_base;
uintptr_t hw_ring_buffer_vaddr;
uintptr_t hw_ring_buffer_paddr;
uintptr_t rx_cookies;
uintptr_t tx_cookies;
uintptr_t rx_free;
uintptr_t rx_used;
uintptr_t tx_free;
uintptr_t tx_used;

extern const keysym_t hidkbd_keydesc_us[];
extern const keysym_t hidkbd_keydesc_uk[];

#define MAX_KEYS 256
#define TX_COUNT 256

#define PACKET_BUFFER_SIZE  sizeof(uint16_t) * MAX_KEYS

/* Make the minimum frame buffer 2k. This is a bit of a waste of memory, but ensures alignment */

#define RXD_EMPTY       (1UL << 15)
#define WRAP            (1UL << 13)

char* kbd_mem_write;
uintptr_t ta_limit;
uint64_t keyboard_size = 0x10000;
int ta_blocks = 256;
int ta_thresh = 16;
int ta_align = 64;

struct descriptor {
    uint16_t len;
    uint16_t stat;
    uint32_t addr;
};

typedef struct {
    unsigned int cnt;
    unsigned int remain;
    unsigned int tail;
    unsigned int head;
    volatile struct descriptor *descr;
    uintptr_t phys;
    void **cookies;
} ring_ctx_t;

ring_ctx_t kbd_ring;

/* Pointers to shared_ringbuffers */
ring_handle_t *kbd_buffer_ring;

static void
ring_setup()
{
    /* set up descriptor rings */
    kbd_ring.cnt = MAX_KEYS;
    kbd_ring.remain = kbd_ring.cnt - 2;
    kbd_ring.tail = 0;
    kbd_ring.head = 0;
    kbd_ring.phys = ring_cp_paddr;
    kbd_ring.cookies = (void **)rx_cookies;
    kbd_ring.descr = (volatile struct descriptor *)hw_ring_buffer_vaddr;
}

static void update_ring_slot(
    ring_ctx_t *ring,
    unsigned int idx,
    uintptr_t phys,
    uint16_t len,
    uint16_t stat)
{
    volatile struct descriptor *d = &(ring->descr[idx]);
    d->addr = phys;
    d->len = len;

    /* Ensure all writes to the descriptor complete, before we set the flags
     * that makes hardware aware of this slot.
     */
    __sync_synchronize();

    d->stat = stat;
}

static uintptr_t 
getPhysAddr(uintptr_t virtual)
{
    uint64_t offset = virtual - dma_cp_vaddr;
    uintptr_t phys;

    if (offset < 0)
        return 0;

    phys = dma_cp_paddr + offset;
    return phys;
}

static uintptr_t 
alloc_rx_buf(size_t buf_size, void **cookie)
{
    uintptr_t addr;
    unsigned int len;

    /* Try to grab a buffer from the free ring */
    if (driver_dequeue(kbd_buffer_ring->free_ring, &addr, &len, cookie)) {
        printf("RX Free ring is empty\n");
        return 0;
    }

    uintptr_t phys = getPhysAddr(addr);

    return getPhysAddr(addr);
}

static void fill_rx_bufs()
{
    ring_ctx_t *ring = &kbd_ring;
    __sync_synchronize();
    while (ring->remain > 0) {
        /* request a buffer */
        void *cookie = NULL;
        uintptr_t phys = alloc_rx_buf(PACKET_BUFFER_SIZE, &cookie); // 
        if (!phys) {
            break;
        }
        uint16_t stat = RXD_EMPTY;
        int idx = ring->tail;
        int new_tail = idx + 1;
        if (new_tail == ring->cnt) {
            new_tail = 0;
            stat |= WRAP;
        }
        ring->cookies[idx] = cookie;
        update_ring_slot(ring, idx, phys, 0, stat);
        ring->tail = new_tail;
        /* There is a race condition if add/remove is not synchronized. */
        ring->remain--;
    }
    __sync_synchronize();
}

void
init_post()
{
    /* Set up shared memory regions */
    ring_init(kbd_buffer_ring, (ring_buffer_t *)rx_free, (ring_buffer_t *)rx_used, NULL, 0);

    fill_rx_bufs();
}

void
process_buffer(char* buffer)
{
    
}

static void 
handle_keypress()
{
    uintptr_t *buffer = 0;
    unsigned int len = 0;
    void *cookie = NULL;

    int index;
    while ((kbd_ring.remain > 1) && !driver_dequeue(kbd_buffer_ring->used_ring, buffer, &len, &cookie)) {
        uint8_t keyPressed = ((char *) buffer)[2];
        if (keyPressed == 0)
            break;
        // first byte is 0x01 for Ctrl, 0x02 for Shft
        uint8_t shiftOrControl = ((char *) buffer)[0];
        int lowercaseAdd = shiftOrControl == 0 ? 1 : 0; // If shift or control held then want to add that value only
        index = 0;
        for (int i = 0; i < 274; i++) {
            if (hidkbd_keydesc_us[i] == KC(keyPressed&CODEMASK)) {
                index = i;
                break;
            }
        }
        keysym_t keypress = hidkbd_keydesc_us[index + lowercaseAdd + shiftOrControl];
        printf("%c", keypress);
    }
}

void
init(void) {
    kbd_buffer_ring = kmem_alloc(sizeof(*kbd_buffer_ring), 0);
    ring_setup();
}

void
notified(microkit_channel ch) {
    switch(ch) {
        case(16):
            printf("kbd_logger notified by similated_kbd. Data   : %c\n", *kbd_mem_write);
            break;
        case 42:
            break;
        case INIT:
            init_post();
            break;
        case TX_CH:
            break;
        case 45:
            handle_keypress();
            break;
        default:
            printf("KBD_LOGGER: Unexpected channel\n");
    }
}
