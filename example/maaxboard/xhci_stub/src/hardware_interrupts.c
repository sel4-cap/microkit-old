#include <sel4cp.h>
#include <printf.h>

#include <evbarm/bus_funcs.h>

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
#include <dev/usb/usb.h>
#include <dev/usb/usbdi.h>
#include <dev/usb/usbdivar.h>
#include <dev/usb/usbhist.h>
#include <dev/usb/usb_mem.h>
#include <dev/usb/xhcireg.h>
#include <dev/usb/xhcivar.h>
#include <sys/device.h>
#include <evbarm/types.h>
#include <sel4_bus_funcs.h>

#include <dev/fdt/fdtvar.h>

uintptr_t xhci_base;
uintptr_t dma_base;
uintptr_t heap_base;
uintptr_t pipe_heap_base;
uintptr_t dma_cp_vaddr = 0x54000000;
uintptr_t dma_cp_paddr;
uintptr_t timer_base;

struct xhci_softc *glob_xhci_sc	= NULL;
struct usbd_bus_methods *xhci_bus_methods_ptr;
uintptr_t xhci_root_intr_pointer;
uintptr_t xhci_root_intr_pointer_other;
bool pipe_thread;

void
init(void) {
    printf("HARDWARE: dmapaddr = %p\n", dma_cp_paddr);
    pipe_thread = false;
    xhci_bus_methods_ptr = get_bus_methods();
    xhci_root_intr_pointer = get_root_intr_methods();
    printf("root_intr_ptr = %p\n", xhci_root_intr_pointer);
    sel4_dma_init(dma_cp_paddr, dma_cp_vaddr, dma_cp_vaddr + 0x200000);
    initialise_and_start_timer(timer_base);
    printf("Hardware up and running\n");
}

void
notified(sel4cp_channel ch) {
    switch (ch) {
        case 6:
            // printf("!!xhci hard interrupt!!\n");
            if (glob_xhci_sc != NULL) {
                xhci_intr(glob_xhci_sc);
            } else {
                printf("FATAL: sc not defined");
            }
            // printf("end of ch\n");
            sel4cp_irq_ack(ch);
            break;
            while (1) {
                
            }
    }
    printf("finished hardware int\n");
    // printf("Hanging to prevent io spam\n");
    // while(1) {

    // }
}

sel4cp_msginfo
protected(sel4cp_channel ch, sel4cp_msginfo msginfo) {
    switch (ch) {
        case 0:
            glob_xhci_sc = (struct xhci_softc *) sel4cp_msginfo_get_label(msginfo);
            return seL4_MessageInfo_new(0,0,0,0);
            break;
        case 1:
            xhci_root_intr_pointer_other = sel4cp_msginfo_get_label(msginfo);
            printf("sending xhci_root_intr_pointer: %p\n", xhci_root_intr_pointer);
            return seL4_MessageInfo_new((uint64_t) xhci_root_intr_pointer, 1, 0, 0);
        default:
            printf("Unexpected channel hardware int %d\n", ch);
    }
}
