/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: GPL-2.0+ 
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
    driver_data.uclass_driver_array[3]  = _u_boot_uclass_driver__clk;
    driver_data.uclass_driver_array[4]  = _u_boot_uclass_driver__usb;
    driver_data.uclass_driver_array[5]  = _u_boot_uclass_driver__usb_hub;
    driver_data.uclass_driver_array[6]  = _u_boot_uclass_driver__usb_dev_generic;
    driver_data.uclass_driver_array[7]  = _u_boot_uclass_driver__phy;
    driver_data.uclass_driver_array[8]  = _u_boot_uclass_driver__usb_mass_storage;
    driver_data.uclass_driver_array[9]  = _u_boot_uclass_driver__blk;
    driver_data.uclass_driver_array[10]  = _u_boot_uclass_driver__keyboard;
    driver_data.uclass_driver_array[11] = _u_boot_uclass_driver__mmc;
    driver_data.uclass_driver_array[12] = _u_boot_uclass_driver__pinconfig;
    driver_data.uclass_driver_array[13] = _u_boot_uclass_driver__pinctrl;
    driver_data.uclass_driver_array[14] = _u_boot_uclass_driver__ethernet;
    driver_data.uclass_driver_array[15] = _u_boot_uclass_driver__led;
    driver_data.uclass_driver_array[16] = _u_boot_uclass_driver__gpio;
    driver_data.uclass_driver_array[17] = _u_boot_uclass_driver__i2c;
    driver_data.uclass_driver_array[18] = _u_boot_uclass_driver__i2c_generic;
    driver_data.uclass_driver_array[19] = _u_boot_uclass_driver__spi;
    driver_data.uclass_driver_array[20] = _u_boot_uclass_driver__spi_generic;

    driver_data.driver_array[0]  = _u_boot_driver__root_driver;
    driver_data.driver_array[1]  = _u_boot_driver__simple_bus;
    driver_data.driver_array[2] = _u_boot_driver__imx8mq_clk;
    driver_data.driver_array[3]  = _u_boot_driver__usb_dev_generic_drv;
    driver_data.driver_array[4]  = _u_boot_driver__usb_generic_hub;
    driver_data.driver_array[5]  = _u_boot_driver__dwc3_generic_wrapper;
    driver_data.driver_array[6]  = _u_boot_driver__dwc3_generic_host;
    driver_data.driver_array[7]  = _u_boot_driver__nxp_imx8mq_usb_phy;
    driver_data.driver_array[8]  = _u_boot_driver__usb_mass_storage;
    driver_data.driver_array[9]  = _u_boot_driver__usb_storage_blk;
    driver_data.driver_array[10]  = _u_boot_driver__usb_kbd;
    driver_data.driver_array[11] = _u_boot_driver__mmc_blk;
    driver_data.driver_array[12] = _u_boot_driver__fsl_esdhc;
    driver_data.driver_array[13] = _u_boot_driver__pinconfig_generic;
    driver_data.driver_array[14] = _u_boot_driver__imx8mq_pinctrl;
    driver_data.driver_array[15] = _u_boot_driver__fecmxc_gem;
    driver_data.driver_array[16] = _u_boot_driver__led_gpio_wrap;
    driver_data.driver_array[17] = _u_boot_driver__led_gpio;
    driver_data.driver_array[18] = _u_boot_driver__gpio_mxc;
    driver_data.driver_array[19] = _u_boot_driver__i2c_mxc;
    driver_data.driver_array[20] = _u_boot_driver__i2c_generic_chip_drv;
    driver_data.driver_array[21] = _u_boot_driver__mxc_spi;
    driver_data.driver_array[22] = _u_boot_driver__spi_generic_drv;
    driver_data.driver_array[23] = _u_boot_driver__clk_gate2;
    driver_data.driver_array[24] = _u_boot_driver__clk_pll1443x;
    driver_data.driver_array[25] = _u_boot_driver__clk_pll1416x;
    driver_data.driver_array[26] = _u_boot_driver__clk_composite;
    driver_data.driver_array[27] = _u_boot_driver__ccf_clk_divider;
    driver_data.driver_array[28] = _u_boot_driver__imx_clk_fixed_factor;
    driver_data.driver_array[29] = _u_boot_driver__fixed_clock;
    driver_data.driver_array[30] = _u_boot_driver__clk_fixed_rate_raw;
    driver_data.driver_array[31] = _u_boot_driver__clk_gate;
    driver_data.driver_array[32] = _u_boot_driver__ccf_clk_mux;

    driver_data.usb_driver_entry_array[0] = _u_boot_usb_driver_entry__usb_generic_hub;
    driver_data.usb_driver_entry_array[1] = _u_boot_usb_driver_entry__usb_mass_storage;
    driver_data.usb_driver_entry_array[2] = _u_boot_usb_driver_entry__usb_kbd;

    /* Note that 'struct part_driver' is read-only so need to copy here rather
     * than perform a simple assignment */
    memcpy(&driver_data.part_driver_array[0], &_u_boot_part_driver__a_efi, sizeof(struct part_driver));
    memcpy(&driver_data.part_driver_array[1], &_u_boot_part_driver__dos, sizeof(struct part_driver));
    memcpy(&driver_data.part_driver_array[2], &_u_boot_part_driver__iso, sizeof(struct part_driver));
    memcpy(&driver_data.part_driver_array[3], &_u_boot_part_driver__mac, sizeof(struct part_driver));

    driver_data.cmd_array[0]  = _u_boot_cmd__dm;
    driver_data.cmd_array[1]  = _u_boot_cmd__usb;
    driver_data.cmd_array[2]  = _u_boot_cmd__env;
    driver_data.cmd_array[3]  = _u_boot_cmd__setenv;
    driver_data.cmd_array[4]  = _u_boot_cmd__mmc;
    driver_data.cmd_array[5]  = _u_boot_cmd__fatsize;
    driver_data.cmd_array[6]  = _u_boot_cmd__fatload;
    driver_data.cmd_array[7]  = _u_boot_cmd__fatls;
    driver_data.cmd_array[8]  = _u_boot_cmd__fatinfo;
    driver_data.cmd_array[9]  = _u_boot_cmd__fatwrite;
    driver_data.cmd_array[10] = _u_boot_cmd__fatrm;
    driver_data.cmd_array[11] = _u_boot_cmd__fatmkdir;
    driver_data.cmd_array[12] = _u_boot_cmd__ext2load;
    driver_data.cmd_array[13] = _u_boot_cmd__ext2ls;
    driver_data.cmd_array[14] = _u_boot_cmd__ext4load;
    driver_data.cmd_array[15] = _u_boot_cmd__ext4ls;
    driver_data.cmd_array[16] = _u_boot_cmd__ext4size;
    driver_data.cmd_array[17] = _u_boot_cmd__ext4write;
    driver_data.cmd_array[18] = _u_boot_cmd__part;
    driver_data.cmd_array[19] = _u_boot_cmd__clocks;
    driver_data.cmd_array[20] = _u_boot_cmd__net;
    driver_data.cmd_array[21] = _u_boot_cmd__dns;
    driver_data.cmd_array[22] = _u_boot_cmd__ping;
    driver_data.cmd_array[23] = _u_boot_cmd__led;
    driver_data.cmd_array[24] = _u_boot_cmd__gpio;
    driver_data.cmd_array[25] = _u_boot_cmd__i2c;
    driver_data.cmd_array[26] = _u_boot_cmd__sspi;
    driver_data.cmd_array[27] = _u_boot_cmd__clk;
    driver_data.cmd_array[28] = _u_boot_cmd__pinmux;

    driver_data.env_clbk_array[0] = _u_boot_env_clbk__ethaddr;
    driver_data.env_clbk_array[1] = _u_boot_env_clbk__ipaddr;
    driver_data.env_clbk_array[2] = _u_boot_env_clbk__gatewayip;
    driver_data.env_clbk_array[3] = _u_boot_env_clbk__netmask;
    driver_data.env_clbk_array[4] = _u_boot_env_clbk__serverip;
    driver_data.env_clbk_array[5] = _u_boot_env_clbk__nvlan;
    driver_data.env_clbk_array[6] = _u_boot_env_clbk__vlan;
    driver_data.env_clbk_array[7] = _u_boot_env_clbk__dnsip;
}
