/* SPDX-License-Identifier: GPL-2.0+
 *
 * (C) Copyright 2000
 * Paolo Scaffardi, AIRVENT SAM s.p.a - RIMINI(ITALY), arsenio@tin.it
 * 
 * (C) Copyright 2022
 * Capgemini Engineering
 */

/* This is a minimal stub of U-Boot's console package providing the subset
 * of functionality required to allow basic input / output devices to be
 * registered and accessed by the driver library.
 */

#include <common.h>
#include <stdio_dev.h>
#include <env.h>

static int console_setfile(int file, struct stdio_dev * dev)
{
	int error = 0;

	if (dev == NULL)
		return -1;

	switch (file) {
	case stdin:
	case stdout:
	case stderr:
		/* Assign the new device */
		stdio_devices[file] = dev;
		break;

	default:		/* Invalid file ID */
		error = -1;
	}
	return error;
}

struct stdio_dev *console_search_dev(int flags, const char *name)
{
	struct stdio_dev *dev;

	dev = stdio_get_by_name(name);

	if (dev && (dev->flags & flags))
		return dev;

	return NULL;
}

int console_assign(int file, const char *devname)
{
	int flag;
	struct stdio_dev *dev;

	/* Check for valid file */
	flag = stdio_file_to_flags(file);
	if (flag < 0)
		return flag;

	/* Check for valid device name */

	dev = console_search_dev(flag, devname);

	if (dev)
		return console_setfile(file, dev);

	return -1;
}

void stdio_print_current_devices(void)
{
	/* Print information */
	puts("In:    ");
	if (stdio_devices[stdin] == NULL) {
		puts("No input devices available!\n");
	} else {
		printf ("%s\n", stdio_devices[stdin]->name);
	}

	puts("Out:   ");
	if (stdio_devices[stdout] == NULL) {
		puts("No output devices available!\n");
	} else {
		printf ("%s\n", stdio_devices[stdout]->name);
	}

	puts("Err:   ");
	if (stdio_devices[stderr] == NULL) {
		puts("No error devices available!\n");
	} else {
		printf ("%s\n", stdio_devices[stderr]->name);
	}
}

int console_init_r(void)
{
	// Set up all file to use the null device.
	int ret;
	for (int i = 0 ; i < MAX_FILES; i++) {
		ret = console_assign(i, "nulldev");
		if (ret != 0) {
			printf("console_init: Unable to assign 'nulldev' to file.\n");
			return -1;
			}
		// Set the environment variable to reflect the selected device.
		env_set(stdio_names[i], "nulldev");
		}

	return 0;
}