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
#define _u_boot_uclass_driver_count     21
#define _u_boot_driver_count            33
#define _u_boot_usb_driver_entry_count  3
#define _u_boot_part_driver_count       4
#define _u_boot_cmd_count               29
#define _u_boot_env_driver_count        0
#define _u_boot_env_clbk_count          8
#define _u_boot_driver_info_count       0
#define _u_boot_udevice_count           0

/* Define the uclass drivers to be used on this platform */
extern struct uclass_driver _u_boot_uclass_driver__nop;
extern struct uclass_driver _u_boot_uclass_driver__root;
extern struct uclass_driver _u_boot_uclass_driver__simple_bus;
extern struct uclass_driver _u_boot_uclass_driver__clk;
extern struct uclass_driver _u_boot_uclass_driver__usb;
extern struct uclass_driver _u_boot_uclass_driver__usb_hub;
extern struct uclass_driver _u_boot_uclass_driver__usb_dev_generic;
extern struct uclass_driver _u_boot_uclass_driver__phy;
extern struct uclass_driver _u_boot_uclass_driver__usb_mass_storage;
extern struct uclass_driver _u_boot_uclass_driver__blk;
extern struct uclass_driver _u_boot_uclass_driver__keyboard;
extern struct uclass_driver _u_boot_uclass_driver__mmc;
extern struct uclass_driver _u_boot_uclass_driver__pinconfig;
extern struct uclass_driver _u_boot_uclass_driver__pinctrl;
extern struct uclass_driver _u_boot_uclass_driver__ethernet;
extern struct uclass_driver _u_boot_uclass_driver__led;
extern struct uclass_driver _u_boot_uclass_driver__gpio;
extern struct uclass_driver _u_boot_uclass_driver__i2c;
extern struct uclass_driver _u_boot_uclass_driver__i2c_generic;
extern struct uclass_driver _u_boot_uclass_driver__spi;
extern struct uclass_driver _u_boot_uclass_driver__spi_generic;

/* Define the drivers to be used on this platform */
extern struct driver _u_boot_driver__root_driver;
extern struct driver _u_boot_driver__simple_bus;
extern struct driver _u_boot_driver__imx8mq_clk;
extern struct driver _u_boot_driver__usb_dev_generic_drv;
extern struct driver _u_boot_driver__usb_generic_hub;
extern struct driver _u_boot_driver__dwc3_generic_wrapper;
extern struct driver _u_boot_driver__dwc3_generic_host;
extern struct driver _u_boot_driver__nxp_imx8mq_usb_phy;
extern struct driver _u_boot_driver__usb_mass_storage;
extern struct driver _u_boot_driver__usb_storage_blk;
extern struct driver _u_boot_driver__usb_kbd;
extern struct driver _u_boot_driver__mmc_blk;
extern struct driver _u_boot_driver__fsl_esdhc;
extern struct driver _u_boot_driver__pinconfig_generic;
extern struct driver _u_boot_driver__imx8mq_pinctrl;
extern struct driver _u_boot_driver__fecmxc_gem;
extern struct driver _u_boot_driver__led_gpio_wrap;
extern struct driver _u_boot_driver__led_gpio;
extern struct driver _u_boot_driver__gpio_mxc;
extern struct driver _u_boot_driver__i2c_mxc;
extern struct driver _u_boot_driver__i2c_generic_chip_drv;
extern struct driver _u_boot_driver__mxc_spi;
extern struct driver _u_boot_driver__spi_generic_drv;
extern struct driver _u_boot_driver__clk_gate2;
extern struct driver _u_boot_driver__clk_pll1443x;
extern struct driver _u_boot_driver__clk_pll1416x;
extern struct driver _u_boot_driver__clk_composite;
extern struct driver _u_boot_driver__ccf_clk_divider;
extern struct driver _u_boot_driver__imx_clk_fixed_factor;
extern struct driver _u_boot_driver__fixed_clock;
extern struct driver _u_boot_driver__clk_fixed_rate_raw;
extern struct driver _u_boot_driver__clk_gate;
extern struct driver _u_boot_driver__ccf_clk_mux;

/* Define the driver entries to be used on this platform */
extern struct usb_driver_entry _u_boot_usb_driver_entry__usb_generic_hub;
extern struct usb_driver_entry _u_boot_usb_driver_entry__usb_mass_storage;
extern struct usb_driver_entry _u_boot_usb_driver_entry__usb_kbd;

/* Define the disk partition types to be used */
extern struct part_driver _u_boot_part_driver__dos;
extern struct part_driver _u_boot_part_driver__a_efi;
extern struct part_driver _u_boot_part_driver__iso;
extern struct part_driver _u_boot_part_driver__mac;

/* Define the u-boot commands to be used on this platform */
extern struct cmd_tbl _u_boot_cmd__dm;
extern struct cmd_tbl _u_boot_cmd__usb;
extern struct cmd_tbl _u_boot_cmd__env;
extern struct cmd_tbl _u_boot_cmd__setenv;
extern struct cmd_tbl _u_boot_cmd__mmc;
extern struct cmd_tbl _u_boot_cmd__fatsize;
extern struct cmd_tbl _u_boot_cmd__fatload;
extern struct cmd_tbl _u_boot_cmd__fatls;
extern struct cmd_tbl _u_boot_cmd__fatinfo;
extern struct cmd_tbl _u_boot_cmd__fatwrite;
extern struct cmd_tbl _u_boot_cmd__fatrm;
extern struct cmd_tbl _u_boot_cmd__fatmkdir;
extern struct cmd_tbl _u_boot_cmd__ext2load;
extern struct cmd_tbl _u_boot_cmd__ext2ls;
extern struct cmd_tbl _u_boot_cmd__ext4load;
extern struct cmd_tbl _u_boot_cmd__ext4ls;
extern struct cmd_tbl _u_boot_cmd__ext4size;
extern struct cmd_tbl _u_boot_cmd__ext4write;
extern struct cmd_tbl _u_boot_cmd__part;
extern struct cmd_tbl _u_boot_cmd__clocks;
extern struct cmd_tbl _u_boot_cmd__net;
extern struct cmd_tbl _u_boot_cmd__dns;
extern struct cmd_tbl _u_boot_cmd__ping;
extern struct cmd_tbl _u_boot_cmd__led;
extern struct cmd_tbl _u_boot_cmd__gpio;
extern struct cmd_tbl _u_boot_cmd__i2c;
extern struct cmd_tbl _u_boot_cmd__sspi;
extern struct cmd_tbl _u_boot_cmd__clk;
extern struct cmd_tbl _u_boot_cmd__pinmux;

/* Define the u-boot environment variables callbacks to be used on this platform */
extern struct env_clbk_tbl _u_boot_env_clbk__ethaddr;
extern struct env_clbk_tbl _u_boot_env_clbk__ipaddr;
extern struct env_clbk_tbl _u_boot_env_clbk__gatewayip;
extern struct env_clbk_tbl _u_boot_env_clbk__netmask;
extern struct env_clbk_tbl _u_boot_env_clbk__serverip;
extern struct env_clbk_tbl _u_boot_env_clbk__nvlan;
extern struct env_clbk_tbl _u_boot_env_clbk__vlan;
extern struct env_clbk_tbl _u_boot_env_clbk__dnsip;