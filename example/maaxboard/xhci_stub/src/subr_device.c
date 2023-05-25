#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: subr_device.c,v 1.13 2022/03/28 12:38:59 riastradh Exp $");

#include <sys/param.h>
#include <sys/device.h>
#include <sys/device_if.h>
#include <sys/device_impl.h>
#include <sys/systm.h>

void *
device_private(device_t dev)
{

	/*
	 * The reason why device_private(NULL) is allowed is to simplify the
	 * work of a lot of userspace request handlers (i.e., c/bdev
	 * handlers) which grab cfdriver_t->cd_units[n].
	 * It avoids having them test for it to be NULL and only then calling
	 * device_private.
	 */
	return dev == NULL ? NULL : dev->dv_private;
}

const char*
device_xname(device_t dev) {
	return "TEMP_NAME"; //current implementation of device doesn't set name, so return this just in case
}

int
device_unit(device_t dev)
{

	return dev->dv_unit;
}