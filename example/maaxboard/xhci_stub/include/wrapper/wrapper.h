#pragma once

// #include <sys/param.h>
#include <sys/bus.h>
#include <sys/device.h>

#include <sys/condvar.h>
#include <dev/usb/usb.h>
#include <dev/usb/usbdi.h>
#include <dev/usb/usbdivar.h>
// #include <dev/usb/usb_mem.h>
#include <dev/usb/xhcireg.h>
#include <dev/usb/xhcivar.h>

#include <dev/fdt/fdtvar.h>

void	dwc3_fdt_attach(device_t, device_t, void *);
void	usb_attach(device_t, device_t, void *);