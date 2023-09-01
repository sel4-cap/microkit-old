//TODO: vimdiff this file
#include <sel4cp.h>
#include <printf.h>

#include <machine/bus_funcs.h>

#include <dev/usb/xhcivar.h>

#include <wrapper.h>
#include <tinyalloc.h>
#include <dma.h>
#include <sys/bus.h>
#include <sys/device.h>
#include <sys/device_impl.h>
#include <sys/intr.h>
// #include <sys/systm.h>
#include <sys/kernel.h>
#include <sys/kmem.h>

#include <timer.h>
#include <shared_ringbuffer.h>
#include <dev/usb/usb.h>
#include <dev/usb/usb_quirks.h>
#include <dev/usb/usbdi.h>
#include <dev/usb/usbdi_util.h>
#include <dev/usb/usbdivar.h>
#include <dev/usb/usbhist.h>
#include <dev/usb/usb_mem.h>
#include <dev/usb/xhcireg.h>
#include <dev/usb/xhcivar.h>
#include <sys/device.h>
#include <machine/types.h>
#include <sel4_bus_funcs.h>

#include <dev/fdt/fdtvar.h>
#include <config_methods.h>

uintptr_t xhci_base;
uintptr_t dma_base;
uintptr_t ring_base;
uintptr_t heap_base;
uintptr_t dma_cp_vaddr = 0x54000000;
uintptr_t dma_cp_paddr;
uintptr_t ring_cp_vaddr = 0x60000000;
uintptr_t ring_cp_paddr;
uintptr_t timer_base;
uint64_t heap_size = 0x2000000;
uintptr_t hw_ring_buffer_vaddr;
uintptr_t hw_ring_buffer_paddr;
uintptr_t rx_cookies;
uintptr_t tx_cookies;
uintptr_t rx_free;
uintptr_t rx_used;
uintptr_t tx_free;
uintptr_t tx_used;

bool pipe_thread;

//extern variables
struct xhci_softc *glob_xhci_sc	= NULL;
struct usbd_bus_methods *xhci_bus_methods_ptr;
struct usbd_pipe_methods *xhci_root_intr_pointer;
struct usbd_pipe_methods *xhci_root_intr_pointer_other;
struct usbd_pipe_methods *device_ctrl_pointer;
struct usbd_pipe_methods *device_ctrl_pointer_other;
struct usbd_pipe_methods *device_intr_pointer;
struct usbd_pipe_methods *device_intr_pointer_other;
struct intr_ptrs_holder *intr_ptrs;
int cold = 1;

/* Pointers to shared_ringbuffers */
ring_handle_t *kbd_buffer_ring;

typedef struct state {
    /* Pointers to shared buffers */
    ring_handle_t rx_ring;
    ring_handle_t tx_ring;
    /*
    //  * Metadata associated with buffers
    //  */
    // ethernet_buffer_t buffer_metadata[NUM_BUFFERS * 2];
} state_t;

state_t state;

void
init(void) {
    printf("SOFTWARE: dmapaddr = %p\n", dma_cp_paddr);
    cold = 0;
    xhci_bus_methods_ptr = get_bus_methods();
    xhci_root_intr_pointer = get_root_intr_methods();
    device_ctrl_pointer = get_device_methods();
    device_intr_pointer = get_device_intr_methods();
    printf("root_intr_ptr = %p\n", xhci_root_intr_pointer);
    pipe_thread = false;
    sel4_dma_init(dma_cp_paddr, dma_cp_vaddr, dma_cp_vaddr + 0x200000);
    initialise_and_start_timer(timer_base);
    printf("Software up and running\n");

    kbd_buffer_ring = kmem_alloc(sizeof(*kbd_buffer_ring), 0);
    ring_init(kbd_buffer_ring, (ring_buffer_t *)rx_free, (ring_buffer_t *)rx_used, NULL, 0);
}

void
notified(sel4cp_channel ch) {
    switch (ch) {
        case 7:
            printf("software interrupt\n");
            if (glob_xhci_sc != NULL) {
                xhci_softintr(&glob_xhci_sc->sc_bus);
            } else {
                printf("FATAL: softintr sc not defined");
            }
            //printf("end of notified software interrupt\n");
            break;
    }
}

sel4cp_msginfo
protected(sel4cp_channel ch, sel4cp_msginfo msginfo) {
    struct set_cfg *cfg;
    switch (ch) {
        case 1:
            xhci_root_intr_pointer_other = (struct usbd_pipe_methods *) sel4cp_msginfo_get_label(msginfo);
            printf("sending xhci_root_intr_pointer: %p\n", xhci_root_intr_pointer);
            return seL4_MessageInfo_new((uint64_t) xhci_root_intr_pointer, 1, 0, 0);
            break;
        case 2:
            glob_xhci_sc = (struct xhci_softc *) sel4cp_msginfo_get_label(msginfo);
            break;
        case 3:
            device_ctrl_pointer_other = (struct usbd_pipe_methods *) sel4cp_msginfo_get_label(msginfo);
            printf("sending device_ctrl_pointer: %p\n", device_ctrl_pointer);
            return seL4_MessageInfo_new((uint64_t) device_ctrl_pointer, 1, 0, 0);
        case 4:
            device_intr_pointer_other = (struct usbd_pipe_methods *) sel4cp_msginfo_get_label(msginfo);
            printf("sending device_intr_pointer: %p\n", device_intr_pointer);
            return seL4_MessageInfo_new((uint64_t) device_intr_pointer, 1, 0, 0);
        case 5:
            usbd_delay_ms(0, 100);
            printf("doing set_config_index in softintr\n");
            cfg = (struct set_cfg*) sel4cp_msginfo_get_label(msginfo);
            cfg->dev->ud_quirks = get_quirks(); //assume no quirks
            printf("config dev = %p\n", cfg->dev);
            usbd_status err = usbd_set_config_index(cfg->dev, cfg->confi, cfg->msg);
            printf("reached end of set_conf_index\n");
            return seL4_MessageInfo_new(err,1,0,0);
        case 8:
            // pass interrupt structures so callback can be used without hardcoding
            intr_ptrs = kmem_alloc(sizeof(struct intr_ptrs_holder), 0);
            intr_ptrs->ukbd     = &ukbd_intr;
            intr_ptrs->ums      = &ums_intr;
            intr_ptrs->uts      = &uts_intr;
            intr_ptrs->uhidev   = &uhidev_intr;
            intr_ptrs->uhub     = &uhub_intr;
            intr_ptrs->uhid     = &uhid_intr;
            return seL4_MessageInfo_new((uint64_t) intr_ptrs, 1, 0, 0);
        default:
            printf("softintr unexpected channel %d\n", ch);
    }
    return seL4_MessageInfo_new(0,0,0,0);
}
