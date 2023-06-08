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
uintptr_t dma_cp_vaddr = 0x54000000;
uintptr_t dma_cp_paddr;

struct xhci_softc *glob_xhci_sc	= NULL;

void
init(void) {
    sel4_dma_init(dma_cp_paddr, dma_cp_vaddr, dma_cp_vaddr + 0x2000000);
    printf("Hardware up and running\n");
}

void
notified(sel4cp_channel ch) {
    switch (ch) {
        case 6:
            printf("!!xhci interrupt!!\n");
            if (glob_xhci_sc != NULL) {
                xhci_intr(glob_xhci_sc);
            } else {
                printf("FATAL: sc not defined");
            }
            sel4cp_irq_ack(ch);
            printf("end of ch\n");
            break;
    }
    printf("Hanging to prevent io spam\n");
    while(1) {

    }
}

sel4cp_msginfo
protected(sel4cp_channel ch, sel4cp_msginfo msginfo) {
    switch (ch) {
        case 0:
            glob_xhci_sc = (uintptr_t) sel4cp_msginfo_get_label(msginfo);
            break;
        default:
            printf("Unexpected channel\n");
    }
    return seL4_MessageInfo_new(0,0,0,0);
}