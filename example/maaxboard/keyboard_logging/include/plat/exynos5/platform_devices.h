/*
 * Copyright 2022 Capgemini Engineering
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * exynos5 arch (aka odroidxu4)
 */

#pragma once

#define CONFIG_SYS_CACHELINE_SIZE 32 //! this might not be right!

#define USB_PHY_REG 0x12100000
#define USB_REG     0x12000000
#define SYSCON_REG  0x10040000
#define PHY_LEN  2

/* List the set of device tree paths that include the 'reg' entries
 * for memory regions that will need to be mapped */
#define REG_USB_0_PATH          "/soc/usb3-0/dwc3@12000000"
// #define REG_USB_0_PATH          "/soc/usb3-0"
#define REG_USB_PHY_0_PATH      "/soc/phy@12100000"
#define REG_USB_1_PATH          "/soc/usb3-1/dwc3@12400000"
#define REG_USB_PHY_1_PATH      "/soc/phy@12500000"
#define REG_USB_PHY_1_PATH      "/soc/phy@12500000"
#define REG_SYSCON_PATH         "/soc/system-controller@10040000"
// #define REG_IC_0_PATH           "/soc/interrupt-controller@10440000"
// #define REG_IC_1_PATH           "/soc/interrupt-controller@10481000"


// #define PERIPHS_PATH "/soc/periphs@c8834000"
#define REG_PATHS { REG_USB_0_PATH, REG_USB_PHY_0_PATH, REG_SYSCON_PATH };
#define REG_PATH_COUNT 3

/* List the set of device tree paths for the devices we wish to access.
 * Note these need to be the root nodes of each device to be accessed */
#define DEV_USB_0_PATH          "/soc/usb3-0"
#define DEV_USB_PHY_0_PATH      REG_USB_PHY_0_PATH
#define DEV_SYSCON_PATH         REG_SYSCON_PATH
// #define DEV_IC_0_PATH           REG_IC_0_PATH
// #define DEV_IC_1_PATH           REG_IC_1_PATH
#define DEV_PATHS { DEV_USB_0_PATH, DEV_USB_PHY_0_PATH, DEV_SYSCON_PATH };
#define DEV_PATH_COUNT 3

/* Provide the hardware settings for CAmkES. Note that we only need to inform
 * CAmkES of the devices with memory mapped regions, i.e. the REG_xxx
 * devices. See https://docs.sel4.systems/projects/camkes for syntax */

#define HARDWARE_INTERFACES                                                     \
    consumes Dummy usb_0;                                                       \
    consumes Dummy usb_phy_0;                                                   \
    consumes Dummy syscon;                                                      \
    emits Dummy dummy_source;

#define HARDWARE_COMPOSITION                                                    \
    connection seL4DTBHardware usb_0_conn(from dummy_source, to usb_0);         \
    connection seL4DTBHardware usb_phy_0_conn(from dummy_source, to usb_phy_0); \
    connection seL4DTBHardware syscon_conn(from dummy_source, to syscon); \
    // connection seL4HardwareInterrupt xhci_irq(from usb_0, to dummy_source);
    // connection sel4HardwareInterrupt xhci_irq(from usb, to usb_0);         \

#define HARDWARE_CONFIGURATION                                                  \
    usb_phy_0.dtb   = dtb({ "path" : REG_USB_PHY_0_PATH });                     \
    usb_0.dtb       = dtb({ "path" : REG_USB_0_PATH });                         \
    syscon.dtb      = dtb({ "path" : REG_SYSCON_PATH });                        \
    usb_0.generate_interrupts  = 1;                                             \
    usb_phy_0.generate_interrupts  = 1;
    // ic_0.generate_interrupts = 1;                                              
