/*
 * Copyright 2022 Capgemini Engineering
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

/* List the set of device tree paths that include the 'reg' entries
 * for memory regions that will need to be mapped */

#define CONFIG_SYS_CACHELINE_SIZE 32 //! this might not be right!

// #define __AARCH64EB__
#define MAAXBOARD   1
#define USB_PHY_REG 0x382f0040
#define USB_REG     0x38200000
#define SYSCON_REG  0x30360000

#define REG_TIMER_PATH      "/soc@0/bus@30400000/timer@306a0000"
#define REG_CCM_PATH        "/soc@0/bus@30000000/clock-controller@30380000"
#define REG_IOMUXC_PATH     "/soc@0/bus@30000000/iomuxc@30330000"
#define REG_OCOTP_PATH      "/soc@0/bus@30000000/ocotp-ctrl@30350000"
#define REG_SYSCON_PATH     "/soc@0/bus@30000000/syscon@30360000"
#define REG_USB_2_PATH      "/soc@0/usb@38200000"
#define REG_USB_PHY_2_PATH  "/soc@0/usb-phy@382f0040"
#define REG_MMC_PATH        "/soc@0/bus@30800000/mmc@30b40000"
#define REG_ETH_PATH        "/soc@0/bus@30800000/ethernet@30be0000"
#define REG_GPIO_1_PATH     "/soc@0/bus@30000000/gpio@30200000"
#define REG_GPIO_2_PATH     "/soc@0/bus@30000000/gpio@30210000"
#define REG_GPIO_3_PATH     "/soc@0/bus@30000000/gpio@30220000"
#define REG_GPIO_4_PATH     "/soc@0/bus@30000000/gpio@30230000"
#define REG_GPIO_5_PATH     "/soc@0/bus@30000000/gpio@30240000"
#define REG_I2C_0_PATH      "/soc@0/bus@30800000/i2c@30a20000"
#define REG_I2C_1_PATH      "/soc@0/bus@30800000/i2c@30a30000"
#define REG_I2C_2_PATH      "/soc@0/bus@30800000/i2c@30a40000"
#define REG_I2C_3_PATH      "/soc@0/bus@30800000/i2c@30a50000"
#define REG_SPI_0_PATH      "/soc@0/bus@30800000/spi@30820000"

#define REG_PATH_COUNT 19

#define REG_PATHS {                                                             \
    REG_USB_2_PATH,                                                             \
    REG_USB_PHY_2_PATH,                                                         \
    REG_MMC_PATH,                                                               \
    REG_ETH_PATH,                                                               \
    REG_TIMER_PATH,                                                             \
    REG_CCM_PATH,                                                               \
    REG_OCOTP_PATH,                                                             \
    REG_SYSCON_PATH,                                                            \
    REG_IOMUXC_PATH,                                                            \
    REG_GPIO_1_PATH,                                                            \
    REG_GPIO_2_PATH,                                                            \
    REG_GPIO_3_PATH,                                                            \
    REG_GPIO_4_PATH,                                                            \
    REG_GPIO_5_PATH,                                                            \
    REG_I2C_0_PATH,                                                             \
    REG_I2C_1_PATH,                                                             \
    REG_I2C_2_PATH,                                                             \
    REG_I2C_3_PATH,                                                             \
    REG_SPI_0_PATH                                                              \
    };

/* List the set of device tree paths for the devices we wish to access.
 * Note these need ot be the root nodes of each device which the
 * the library supplies a driver */

#define DEV_TIMER_PATH      REG_TIMER_PATH
#define DEV_CCM_PATH        REG_CCM_PATH
#define DEV_IOMUXC_PATH     REG_IOMUXC_PATH
#define DEV_OCOTP_PATH      REG_OCOTP_PATH
#define DEV_SYSCON_PATH     REG_SYSCON_PATH
#define DEV_USB_2_PATH      REG_USB_2_PATH
#define DEV_USB_PHY_2_PATH  REG_USB_PHY_2_PATH
#define DEV_MMC_PATH        REG_MMC_PATH
#define DEV_ETH_PATH        REG_ETH_PATH
#define DEV_GPIO_1_PATH     REG_GPIO_1_PATH
#define DEV_GPIO_2_PATH     REG_GPIO_2_PATH
#define DEV_GPIO_3_PATH     REG_GPIO_3_PATH
#define DEV_GPIO_4_PATH     REG_GPIO_4_PATH
#define DEV_GPIO_5_PATH     REG_GPIO_5_PATH
#define DEV_I2C_0_PATH      REG_I2C_0_PATH
#define DEV_I2C_1_PATH      REG_I2C_1_PATH
#define DEV_I2C_2_PATH      REG_I2C_2_PATH
#define DEV_I2C_3_PATH      REG_I2C_3_PATH
#define DEV_SPI_0_PATH      REG_SPI_0_PATH
#define DEV_LEDS_PATH       "/leds"
#define DEV_CLK_1_PATH      "/clock-ckil"
#define DEV_CLK_2_PATH      "/clock-osc-25m"
#define DEV_CLK_3_PATH      "/clock-osc-27m"
#define DEV_CLK_4_PATH      "/clock-ext1"
#define DEV_CLK_5_PATH      "/clock-ext2"
#define DEV_CLK_6_PATH      "/clock-ext3"
#define DEV_CLK_7_PATH      "/clock-ext4"

#define DEV_PATH_COUNT 27

#define DEV_PATHS {                                                             \
    DEV_USB_2_PATH,                                                             \
    DEV_USB_PHY_2_PATH,                                                         \
    DEV_MMC_PATH,                                                               \
    DEV_ETH_PATH,                                                               \
    DEV_TIMER_PATH,                                                             \
    DEV_CCM_PATH,                                                               \
    DEV_OCOTP_PATH,                                                             \
    DEV_SYSCON_PATH,                                                            \
    DEV_IOMUXC_PATH,                                                            \
    DEV_GPIO_1_PATH,                                                            \
    DEV_GPIO_2_PATH,                                                            \
    DEV_GPIO_3_PATH,                                                            \
    DEV_GPIO_4_PATH,                                                            \
    DEV_GPIO_5_PATH,                                                            \
    DEV_I2C_0_PATH,                                                             \
    DEV_I2C_1_PATH,                                                             \
    DEV_I2C_2_PATH,                                                             \
    DEV_I2C_3_PATH,                                                             \
    DEV_SPI_0_PATH,                                                             \
    DEV_LEDS_PATH,                                                              \
    DEV_CLK_1_PATH,                                                             \
    DEV_CLK_2_PATH,                                                             \
    DEV_CLK_3_PATH,                                                             \
    DEV_CLK_4_PATH,                                                             \
    DEV_CLK_5_PATH,                                                             \
    DEV_CLK_6_PATH,                                                             \
    DEV_CLK_7_PATH                                                              \
    };

/* Provide the hardware settings for CAmkES. Note that we only need to inform
 * CAmkES with the devices with memory mapped regions, i.e. the REG_xxx
 * devices. */

#define HARDWARE_INTERFACES                                                     \
    consumes Dummy usb_0;                                                       \
    consumes Dummy usb_phy_0;                                                   \
    consumes Dummy mmc;                                                         \
    consumes Dummy eth;                                                         \
    consumes Dummy timer;                                                       \
    consumes Dummy ccm;                                                         \
    consumes Dummy iomuxc;                                                      \
    consumes Dummy ocotp;                                                       \
    consumes Dummy syscon;                                                      \
    consumes Dummy gpio_1;                                                      \
    consumes Dummy gpio_2;                                                      \
    consumes Dummy gpio_3;                                                      \
    consumes Dummy gpio_4;                                                      \
    consumes Dummy gpio_5;                                                      \
    consumes Dummy i2c_0;                                                       \
    consumes Dummy i2c_1;                                                       \
    consumes Dummy i2c_2;                                                       \
    consumes Dummy i2c_3;                                                       \
    consumes Dummy spi_0;                                                       \
    emits Dummy dummy_source;

#define HARDWARE_COMPOSITION                                                    \
    connection seL4DTBHardware usb_0_conn(from dummy_source, to usb_0);         \
    connection seL4DTBHardware usb_phy_0_conn(from dummy_source, to usb_phy_0); \
    connection seL4DTBHardware mmc_conn(from dummy_source, to mmc);             \
    connection seL4DTBHardware eth_conn(from dummy_source, to eth);             \
    connection seL4DTBHardware timer_conn(from dummy_source, to timer);         \
    connection seL4DTBHardware ccm_conn(from dummy_source, to ccm);             \
    connection seL4DTBHardware syscon_conn(from dummy_source, to syscon);       \
    connection seL4DTBHardware ocotp_conn(from dummy_source, to ocotp);         \
    connection seL4DTBHardware iomuxc_conn(from dummy_source, to iomuxc);       \
    connection seL4DTBHardware gpio_1_conn(from dummy_source, to gpio_1);       \
    connection seL4DTBHardware gpio_2_conn(from dummy_source, to gpio_2);       \
    connection seL4DTBHardware gpio_3_conn(from dummy_source, to gpio_3);       \
    connection seL4DTBHardware gpio_4_conn(from dummy_source, to gpio_4);       \
    connection seL4DTBHardware gpio_5_conn(from dummy_source, to gpio_5);       \
    connection seL4DTBHardware i2c_0_conn(from dummy_source, to i2c_0);         \
    connection seL4DTBHardware i2c_1_conn(from dummy_source, to i2c_1);         \
    connection seL4DTBHardware i2c_2_conn(from dummy_source, to i2c_2);         \
    connection seL4DTBHardware i2c_3_conn(from dummy_source, to i2c_3);         \
    connection seL4DTBHardware spi_0_conn(from dummy_source, to spi_0);

#define HARDWARE_CONFIGURATION                                                  \
    usb_0.dtb     = dtb({ "path" : REG_USB_2_PATH });                           \
    usb_phy_0.dtb = dtb({ "path" : REG_USB_PHY_2_PATH });                       \
    mmc.dtb       = dtb({ "path" : REG_MMC_PATH });                             \
    eth.dtb       = dtb({ "path" : REG_ETH_PATH });                             \
    timer.dtb     = dtb({ "path" : REG_TIMER_PATH });                           \
    ccm.dtb       = dtb({ "path" : REG_CCM_PATH });                             \
    syscon.dtb    = dtb({ "path" : REG_SYSCON_PATH });                          \
    ocotp.dtb     = dtb({ "path" : REG_OCOTP_PATH });                           \
    iomuxc.dtb    = dtb({ "path" : REG_IOMUXC_PATH });                          \
    gpio_1.dtb    = dtb({ "path" : REG_GPIO_1_PATH });                          \
    gpio_2.dtb    = dtb({ "path" : REG_GPIO_2_PATH });                          \
    gpio_3.dtb    = dtb({ "path" : REG_GPIO_3_PATH });                          \
    gpio_4.dtb    = dtb({ "path" : REG_GPIO_4_PATH });                          \
    gpio_5.dtb    = dtb({ "path" : REG_GPIO_5_PATH });                          \
    i2c_0.dtb     = dtb({ "path" : REG_I2C_0_PATH });                           \
    i2c_1.dtb     = dtb({ "path" : REG_I2C_1_PATH });                           \
    i2c_2.dtb     = dtb({ "path" : REG_I2C_2_PATH });                           \
    i2c_3.dtb     = dtb({ "path" : REG_I2C_3_PATH });                           \
    spi_0.dtb     = dtb({ "path" : REG_SPI_0_PATH });                           \
    usb_0.generate_interrupts  = 1;                                             \
    usb_phy_0.generate_interrupts  = 1;