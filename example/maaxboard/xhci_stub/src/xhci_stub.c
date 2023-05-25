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
#define BUS_DEBUG 0
#define __AARCH64__

bool int_once = false;
struct xhci_softc *glob_xhci_sc	= NULL;
struct usb_softc *glob_usb_sc 	= NULL;

struct usb_softc {
	struct usbd_bus *sc_bus;	/* USB controller */
	struct usbd_port sc_port;	/* dummy port for root hub */

	struct lwp	*sc_event_thread;
	struct lwp	*sc_attach_thread;

	char		sc_dying;
	bool		sc_pmf_registered;
};

struct imx8mq_usbphy_softc {
	device_t		sc_dev;
	bus_space_tag_t		sc_bst;
	bus_space_handle_t	sc_bsh;
	int			sc_phandle;
};

// definitions from .system file
uintptr_t xhci_base;
uintptr_t xhci_phy_base;
uintptr_t heap_base;
uintptr_t dma_base;
uintptr_t dma_cp_paddr;
uintptr_t dma_cp_vaddr = 0x54000000;
uintptr_t ta_limit;

// TODO: put these in a header file so can change it in a single place for a platform
uint64_t heap_size = 0x2000000;
int ta_blocks = 256;
int ta_thresh = 16;
int ta_align = 64;

int phy_setup() {
    printf("setting up phy (imx8)\n");
    struct imx8mq_usbphy_softc *sc_usbphy;
	sc_usbphy = kmem_alloc(sizeof(*sc_usbphy), 0);
    device_t parent_usbphy = NULL;
    device_t self_usbphy = kmem_alloc(sizeof(device_t), 0);
    void *aux_usbphy = kmem_alloc(sizeof(struct fdt_attach_args), 0);
	sc_usbphy->sc_bsh = 0x382f0040;
	sc_usbphy->sc_bst = kmem_alloc(sizeof(bus_space_tag_t), 0);
	self_usbphy->dv_private = sc_usbphy;
	printf("starting phy attach\n");
	imx8mq_usbphy_attach(parent_usbphy, self_usbphy,aux_usbphy);


	printf("enable phy...\n");
    imx8mq_usbphy_enable(self_usbphy, NULL, true); //imx8 doesn't need priv 
    return 0;
}

void
init(void) {
    if (BUS_DEBUG) {
        uint32_t read_offset    = 0xc120;
        // uint32_t write_offset   = 0xc2c0;

        sel4cp_dbg_puts("Starting read and write tests\n");
        /* read test */
        printf("xhci_base: %p\n", xhci_base);
        uint32_t response;
        response  = bus_space_read_1(0, xhci_base, read_offset);
        printf("Attempted bus_space_read_1: %p\n", response);
        response  = bus_space_read_4(0, xhci_base, 0xc120);
        printf("Attempted bus_space_read_4: %p\n", response);
    }

    // init
    printf("hello, starting stack bashing:)\n");
    ta_limit = heap_base + heap_size;
    printf("stack from %p to %p\n", heap_base, ta_limit);
    bool error = ta_init((void*)heap_base, (void*)ta_limit, ta_blocks, ta_thresh, ta_align);
    printf("Init malloc: %d\n", error);

    sel4_dma_init(dma_cp_paddr, dma_cp_vaddr, dma_cp_vaddr + 0x2000000);
    printf("dma init ok\n");

    device_t parent_xhci = NULL;
    printf("Allocing mem\n");

    phy_setup();
    device_t self_xhci = kmem_alloc(sizeof(device_t), 0);
    void *aux_xhci = kmem_alloc(sizeof(struct fdt_attach_args), 0);
    printf("Alloc ok\n");

    struct xhci_softc *sc_xhci = kmem_alloc(sizeof(struct xhci_softc), 0);
    glob_xhci_sc = sc_xhci;
    sc_xhci->sc_ioh=0x38200000;
	bus_space_tag_t iot = kmem_alloc(sizeof(bus_space_tag_t), 0);
    sc_xhci->sc_iot=iot;

    __sync_synchronize();

    self_xhci->dv_private = sc_xhci;

    printf("Starting fdt_attach\n");
    dwc3_fdt_attach(parent_xhci,self_xhci,aux_xhci);
}



void
notified(sel4cp_channel ch)
{
    switch(ch) {
        case 7:
            //handle interrupt
            printf("!!xhci interrupt!!\n");
            if (glob_xhci_sc != NULL) {
                xhci_intr(glob_xhci_sc);
            } else {
                printf("FATAL: sc not defined");
            }

            if (!int_once) {
                int_once = true;
                struct usb_softc *usb_sc = kmem_alloc(sizeof(struct usb_softc),0);
                struct usbd_bus *sc_bus = kmem_alloc(sizeof(struct usbd_bus),0);
                device_t self = kmem_alloc(sizeof(device_t), 0);
                *sc_bus = glob_xhci_sc->sc_bus;
                sc_bus->ub_methods = glob_xhci_sc->sc_bus.ub_methods;
                printf("does sc_bus have newdev? %d\n", (sc_bus->ub_methods->ubm_newdev != NULL));
                // sc_bus->ub_revision = USBREV_3_0;
                self->dv_unit = 1;
                self->dv_private = usb_sc;
                device_t parent = NULL;
                usb_attach(parent, self, sc_bus);
                // usbd_new_device();
            }
            printf("end of ch\n");
            return;
        default:
            printf("idiot boy, unexpected interrupt channel\n");
            break;
    }
}
