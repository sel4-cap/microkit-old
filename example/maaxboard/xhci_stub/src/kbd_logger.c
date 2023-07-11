#include <sel4cp.h>
#include <printf.h>
#include <shared_ringbuffer.h>
#include <tinyalloc.h>

#define INIT  42
#define TX_CH 43

uintptr_t timer_base;
uintptr_t xhci_base;
uintptr_t dma_base;
uintptr_t heap_base;
uintptr_t pipe_heap_base;
uintptr_t dma_cp_vaddr = 0x54000000;
uintptr_t dma_cp_paddr;
uintptr_t keyboard_base;
uintptr_t hw_ring_buffer_vaddr;
uintptr_t hw_ring_buffer_paddr;
uintptr_t rx_cookies;
uintptr_t tx_cookies;
uintptr_t rx_free;
uintptr_t rx_used;
uintptr_t tx_free;
uintptr_t tx_used;

/* Make the minimum frame buffer 2k. This is a bit of a waste of memory, but ensures alignment */
#define PACKET_BUFFER_SIZE  2048
#define MAX_PACKET_SIZE     1536

#define RXD_EMPTY       (1UL << 15)
#define WRAP            (1UL << 13)

#define RX_COUNT 256
#define TX_COUNT 256

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

ring_ctx_t rx;
ring_ctx_t tx;

/* Pointers to shared_ringbuffers */
ring_handle_t rx_ring;
ring_handle_t tx_ring;

static void
ring_setup()
{
    /* set up descriptor rings */
    rx.cnt = RX_COUNT;
    rx.remain = rx.cnt - 2;
    rx.tail = 0;
    rx.head = 0;
    rx.phys = dma_cp_paddr;
    rx.cookies = (void **)rx_cookies;
    rx.descr = (volatile struct descriptor *)hw_ring_buffer_vaddr;

    tx.cnt = TX_COUNT;
    tx.remain = tx.cnt - 2;
    tx.tail = 0;
    tx.head = 0;
    tx.phys = dma_cp_paddr + (sizeof(struct descriptor) * RX_COUNT);
    tx.cookies = (void **)tx_cookies;
    tx.descr = (volatile struct descriptor *)(hw_ring_buffer_vaddr + (sizeof(struct descriptor) * RX_COUNT));
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

    if (offset < 0) {
        printf("getPhysAddr: offset < 0");
        return 0;
    }

    phys = dma_cp_paddr + offset;
    return phys;
}

static uintptr_t 
alloc_rx_buf(size_t buf_size, void **cookie)
{
    uintptr_t addr;
    unsigned int len;

    /* Try to grab a buffer from the free ring */
    if (driver_dequeue(rx_ring.free_ring, &addr, &len, cookie)) {
        printf("RX Free ring is empty\n");
        return 0;
    }

    uintptr_t phys = getPhysAddr(addr);

    return getPhysAddr(addr);
}

static void fill_rx_bufs()
{
    ring_ctx_t *ring = &rx;
    __sync_synchronize();
    while (ring->remain > 0) {
        /* request a buffer */
        void *cookie = NULL;
        uintptr_t phys = alloc_rx_buf(MAX_PACKET_SIZE, &cookie);
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

    // if (ring->tail != ring->head) {
    //     /* Make sure rx is enabled */
    //     eth->rdar = RDAR_RDAR;
    // }
}

void
init_post()
{
    /* Set up shared memory regions */
    ring_init(&rx_ring, (ring_buffer_t *)rx_free, (ring_buffer_t *)rx_used, NULL, 0);
    ring_init(&tx_ring, (ring_buffer_t *)tx_free, (ring_buffer_t *)tx_used, NULL, 0);

    fill_rx_bufs();
}

void
init(void) {
    sel4cp_dbg_puts(sel4cp_name);
    printf("KBD_LOGGER\n");

    ring_setup();
    ta_limit = keyboard_base + keyboard_size;
    bool error = ta_init((void*)keyboard_base, (void*)ta_limit, ta_blocks, ta_thresh, ta_align);
    printf("Init malloc: %d\n", error);
    kbd_mem_write = ta_alloc(sizeof(char));
    printf("Sending memory address to be written to %p\n", kbd_mem_write);
    sel4cp_msginfo addr = sel4cp_ppcall(13, seL4_MessageInfo_new((uint64_t) kbd_mem_write,1,0,0));
}

void
notified(sel4cp_channel ch) {
    switch(ch) {
        case(16):
            ;
            // char data = *kbd_mem_write;
            printf("kbd_logger notified by similated_kbd. Data   : %c\n", *kbd_mem_write);
        case INIT:
            init_post();
        case TX_CH:
            
    }
}
