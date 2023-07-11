/*	$NetBSD: wskbd.h,v 1.1 2015/08/24 23:01:59 pooka Exp $	*/
#include <stdint.h>
#include <printf.h>
#include <sys/bus.h>
#include <dev/usb/usbdi.h>

#define NWSKBD 1

void wskbd_attach(device_t, device_t, void *);