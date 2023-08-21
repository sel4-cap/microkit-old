#include <sel4_bus_funcs.h>
#include <sel4dma.h>
#include <evbarm/bus_funcs.h>

#include <dev/usb/xhcivar.h>

#include <wrapper.h>
#include <sys/bus.h>
#include <sys/device.h>
#include <printf.h>
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

struct imx8mq_usbphy_softc {
	device_t		sc_dev;
	bus_space_tag_t		sc_bst;
	bus_space_handle_t	sc_bsh;
	int			sc_phandle;
};

int phy_setup() {
    printf("setting up phy (imx8)\n");
    struct imx8mq_usbphy_softc *sc_usbphy;
	sc_usbphy = malloc(sizeof(*sc_usbphy));
    device_t parent_usbphy = NULL;
    device_t self_usbphy = malloc(sizeof(device_t));
    void *aux_usbphy = malloc(sizeof(struct fdt_attach_args));
	sc_usbphy->sc_bsh = USB_PHY_REG;
	sc_usbphy->sc_bst = malloc(sizeof(bus_space_tag_t));
	self_usbphy->dv_private = sc_usbphy;
	printf("starting phy attach\n");
	imx8mq_usbphy_attach(parent_usbphy, self_usbphy,aux_usbphy);


	printf("enable phy...\n");
    imx8mq_usbphy_enable(self_usbphy, NULL, true); //imx8 doesn't need priv 
    return 0;
}