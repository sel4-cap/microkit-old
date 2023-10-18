/*
 * Copyright 2022, Capgemini Engineering
 *
 * SPDX-License-Identifier: BSD-2-Clause
 * 
 * This file defines which drivers, driver classes, driver entries and commands
 * are to be included in the compiled library for this platform.
 *
 * This allows only the drivers compatible with the targeted platform to be
 * included with all non-compatible drivers excluded.
 *
 * It should be noted that some of these are fundamental to allowing the U-Boot
 * driver model to function (e.g. the nop, root and simple bus drivers).
 */

/* Define the number of different driver elements to be used on this platform */
#define _u_boot_uclass_driver_count     9
#define _u_boot_driver_count            7
#define _u_boot_usb_driver_entry_count  0
#define _u_boot_part_driver_count       0
#define _u_boot_cmd_count               6
#define _u_boot_env_driver_count        0
#define _u_boot_env_clbk_count          0
#define _u_boot_driver_info_count       0
#define _u_boot_udevice_count           0

/* Define the uclass drivers to be used on this platform */
extern struct uclass_driver _u_boot_uclass_driver__nop;
extern struct uclass_driver _u_boot_uclass_driver__root;
extern struct uclass_driver _u_boot_uclass_driver__simple_bus;
extern struct uclass_driver _u_boot_uclass_driver__phy;
extern struct uclass_driver _u_boot_uclass_driver__blk;
extern struct uclass_driver _u_boot_uclass_driver__pinconfig;
extern struct uclass_driver _u_boot_uclass_driver__pinctrl;
extern struct uclass_driver _u_boot_uclass_driver__gpio;
extern struct uclass_driver _u_boot_uclass_driver__led;

/* Define the drivers to be used on this platform */
extern struct driver _u_boot_driver__root_driver;
extern struct driver _u_boot_driver__simple_bus;
extern struct driver _u_boot_driver__pinconfig_generic;
extern struct driver _u_boot_driver__meson_gxbb_pinctrl;
extern struct driver _u_boot_driver__meson_gx_gpio_driver;
extern struct driver _u_boot_driver__led_gpio_wrap;
extern struct driver _u_boot_driver__led_gpio;

/* Define the driver entries to be used on this platform */

/* Define the disk partition types to be used */

/* Define the u-boot commands to be used on this platform */
extern struct cmd_tbl _u_boot_cmd__dm;
extern struct cmd_tbl _u_boot_cmd__env;
extern struct cmd_tbl _u_boot_cmd__setenv;
extern struct cmd_tbl _u_boot_cmd__pinmux;
extern struct cmd_tbl _u_boot_cmd__gpio;
extern struct cmd_tbl _u_boot_cmd__led;

/* Define the u-boot environment variables callbacks to be used on this platform */
