/*
 * Copyright 2022 Capgemini Engineering
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

/* List the set of device tree paths that include the 'reg' entries
 * for memory regions that will need to be mapped */
#define BUS_PATH     "/soc/bus@c8100000"
#define PERIPHS_PATH "/soc/periphs@c8834000"
#define REG_PATHS { BUS_PATH, PERIPHS_PATH };
#define REG_PATH_COUNT 2

/* List the set of device tree paths for the devices we wish to access.
 * Note these need to be the root nodes of each device to be accessed */
#define PINCTRL1_PATH "/soc/bus@c8100000/pinctrl@14"
#define PINCTRL2_PATH "/soc/periphs@c8834000/pinctrl@4b0"
#define LEDS_PATH "/leds"
#define DEV_PATHS { PINCTRL1_PATH, PINCTRL2_PATH, LEDS_PATH };
#define DEV_PATH_COUNT 3

/* Provide the hardware settings for CAmkES. Note that we only need to inform
 * CAmkES of the devices with memory mapped regions, i.e. the REG_xxx
 * devices. See https://docs.sel4.systems/projects/camkes for syntax */

#define HARDWARE_INTERFACES                                                 \
    consumes Dummy bus;                                                     \
    consumes Dummy periphs;                                                 \
    emits Dummy dummy_source;

#define HARDWARE_COMPOSITION                                                \
    connection seL4DTBHardware bus_conn(from dummy_source, to bus);         \
    connection seL4DTBHardware periphs_conn(from dummy_source, to periphs);

#define HARDWARE_CONFIGURATION                                              \
    bus.dtb     = dtb({ "path" : BUS_PATH });                               \
    periphs.dtb = dtb({ "path" : PERIPHS_PATH });
