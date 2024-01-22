 /* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

#include <uboot_helper.h>
#include <driver_data.h>

#include <dm/device.h>
#include <dm/uclass.h>
#include <dm/platdata.h>
#include <usb.h>
#include <part.h>

void initialise_driver_data(void) {
    driver_data.uclass_driver_array[0]  = _u_boot_uclass_driver__nop;
    driver_data.uclass_driver_array[1]  = _u_boot_uclass_driver__root;
    driver_data.uclass_driver_array[2]  = _u_boot_uclass_driver__simple_bus;
    driver_data.uclass_driver_array[3]  = _u_boot_uclass_driver__phy;
    driver_data.uclass_driver_array[4]  = _u_boot_uclass_driver__blk;
    driver_data.uclass_driver_array[5]  = _u_boot_uclass_driver__pinconfig;
    driver_data.uclass_driver_array[6]  = _u_boot_uclass_driver__pinctrl;
    driver_data.uclass_driver_array[7]  = _u_boot_uclass_driver__gpio;
    driver_data.uclass_driver_array[8]  = _u_boot_uclass_driver__led;

    driver_data.driver_array[0]  = _u_boot_driver__root_driver;
    driver_data.driver_array[1]  = _u_boot_driver__simple_bus;
    driver_data.driver_array[2]  = _u_boot_driver__pinconfig_generic;
    driver_data.driver_array[3]  = _u_boot_driver__meson_gxbb_pinctrl;
    driver_data.driver_array[4]  = _u_boot_driver__meson_gx_gpio_driver;
    driver_data.driver_array[5]  = _u_boot_driver__led_gpio_wrap;
    driver_data.driver_array[6]  = _u_boot_driver__led_gpio;

    driver_data.cmd_array[0]  = _u_boot_cmd__dm;
    driver_data.cmd_array[1]  = _u_boot_cmd__env;
    driver_data.cmd_array[2]  = _u_boot_cmd__setenv;
    driver_data.cmd_array[3]  = _u_boot_cmd__pinmux;
    driver_data.cmd_array[4]  = _u_boot_cmd__gpio;
    driver_data.cmd_array[5]  = _u_boot_cmd__led;
}
