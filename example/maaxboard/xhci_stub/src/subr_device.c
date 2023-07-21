//TODO: vimdiff this file
#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: subr_device.c,v 1.13 2022/03/28 12:38:59 riastradh Exp $");

#include <sys/param.h>
#include <sys/device.h>
#include <sys/device_if.h>
#include <sys/device_impl.h>
#include <sys/systm.h>
#include <lib/libkern/libkern.h>

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
	return dev->dv_xname;
}

int
device_unit(device_t dev)
{

	return dev->dv_unit;
}

device_t
device_parent(device_t dev)
{

	return dev->dv_parent;
}

/*
 * device_is_a:
 *
 *	Returns true if the device is an instance of the specified
 *	driver.
 */
bool
device_is_a(device_t dev, const char *dname)
{
	if (dev == NULL || dev->dv_cfdriver == NULL) {
		return false;
	}

	return strcmp(dev->dv_cfdriver->cd_name, dname) == 0;
}

prop_dictionary_t
device_properties(device_t dev)
{

	return dev->dv_properties;
}