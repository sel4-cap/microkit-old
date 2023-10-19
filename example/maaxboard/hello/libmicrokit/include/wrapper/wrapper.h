/* This work is Crown Copyright NCSC, 2023. */
#pragma once

#include <sys/bus.h>
#include <sys/device.h>

#include <sys/condvar.h>
#include <dev/usb/usb.h>
#include <dev/usb/usbdi.h>
#include <dev/usb/usbdivar.h>
#include <dev/usb/xhcireg.h>
#include <dev/usb/xhcivar.h>

#include <dev/fdt/fdtvar.h>

struct usb_softc {
#if 0
	device_t	sc_dev;		/* base device */
#endif
	struct usbd_bus *sc_bus;	/* USB controller */
	struct usbd_port sc_port;	/* dummy port for root hub */

	struct lwp	*sc_event_thread;
	struct lwp	*sc_attach_thread;

	char		sc_dying;
	bool		sc_pmf_registered;
};

void	dwc3_fdt_attach(device_t, device_t, void *);
void	usb_attach(device_t, device_t, void *);
void    usb_discover(struct usb_softc *);