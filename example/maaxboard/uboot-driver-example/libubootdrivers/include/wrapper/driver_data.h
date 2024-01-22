/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: GPL-2.0+ 
 *
 */

#ifndef	__DRIVER_DATA_H
#define __DRIVER_DATA_H

#include <plat_driver_data.h>

#include <dm/device.h>
#include <dm/uclass.h>
#include <dm/platdata.h>
#include <usb.h>
#include <command.h>
#include <env.h>
#include <env_internal.h>
#include <part.h>

struct driver_data_t {
    struct driver driver_array[_u_boot_driver_count];
	struct uclass_driver uclass_driver_array[_u_boot_uclass_driver_count];
    struct usb_driver_entry usb_driver_entry_array[_u_boot_usb_driver_entry_count];
    struct cmd_tbl cmd_array[_u_boot_cmd_count];
    struct part_driver part_driver_array[_u_boot_part_driver_count];
    struct env_driver env_driver_array[_u_boot_env_driver_count];
    struct env_clbk_tbl env_clbk_array[_u_boot_env_clbk_count];
    struct driver_info driver_info_array[_u_boot_driver_info_count];
    struct udevice udevice_array[_u_boot_udevice_count];
};

extern struct driver_data_t driver_data;

void initialise_driver_data(void);

#endif /* __DRIVER_DATA_H */