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
            sel4cp_irq_ack(73);
            printf("end of ch\n");
            // if (!int_once) {
            //     int_once = true;
            //     struct usb_softc *usb_sc = kmem_alloc(sizeof(struct usb_softc),0);
            //     struct usbd_bus *sc_bus = kmem_alloc(sizeof(struct usbd_bus),0);
            //     device_t self = kmem_alloc(sizeof(device_t), 0);
            //     *sc_bus = glob_xhci_sc->sc_bus;
            //     sc_bus->ub_methods = glob_xhci_sc->sc_bus.ub_methods;
            //     printf("does sc_bus have newdev? %d\n", (sc_bus->ub_methods->ubm_newdev != NULL));
            //     // sc_bus->ub_revision = USBREV_3_0;
            //     self->dv_unit = 1;
            //     self->dv_private = usb_sc;
            //     device_t parent = NULL;
            //     usb_attach(parent, self, sc_bus);
            //     // usbd_new_device();
            // }
            break;
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