#include <io.h>
#define DELAY(ms) ps_udelay(ms*1000);

#include <sel4_bus_funcs.h>
#include <sel4dma.h>
#include <platform_devices.h>
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

struct exynos_usbdrdphy {
	struct exynos_usbdrdphy_softc *phy_sc;
	u_int			phy_index;
};

struct exynos_usbdrdphy_softc {
	device_t		sc_dev;
	bus_space_tag_t		sc_bst;
	bus_space_handle_t	sc_bsh;
	int			sc_phandle;
	struct syscon		*sc_pmureg;

	struct exynos_usbdrdphy	*sc_phy;
	u_int			sc_nphy;

	struct fdtbus_gpio_pin	*sc_gpio_id_det;
	struct fdtbus_gpio_pin	*sc_gpio_vbus_det;
};

int phy_setup() {
    printf("setting up phy (exynos5)\n");
    struct exynos_usbdrdphy_softc *sc_usbphy;
	sc_usbphy = malloc(sizeof(*sc_usbphy));
    device_t parent_usbphy = NULL;
    device_t self_usbphy = malloc(sizeof(device_t));
    void *aux_usbphy = malloc(sizeof(struct fdt_attach_args));
	sc_usbphy->sc_bsh = USB_PHY_REG;
	self_usbphy->dv_private = sc_usbphy;
	printf("starting phy attach\n");
	exynos_usbdrdphy_attach(parent_usbphy, self_usbphy,aux_usbphy);


	printf("enable phy...\n");
	for (int n = 0; n < PHY_LEN; n++) {
		struct exynos_usbdrdphy * priv_usbphy = malloc(sizeof(struct exynos_usbdrdphy));
		priv_usbphy->phy_sc = sc_usbphy;
		priv_usbphy->phy_index = n;
		exynos_usbdrdphy_enable(self_usbphy, priv_usbphy, true);
	}
    return 0;
}