/*
 * Copyright 2021, Breakaway Consulting Pty. Ltd.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <microkit.h>
#include <dma.h>
#include <uboot_drivers.h>
#include <string.h>
// #include <stdint.h>
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <public_api/stdio_microkit.h>

// fdt initialise 
#define STR(x) #x
#define INCBIN_SECTION ".rodata"
#define INCBIN(name, file) \
    __asm__(".section " INCBIN_SECTION "\n" \
            ".global incbin_" STR(name) "_start\n" \
            ".balign 16\n" \
            "incbin_" STR(name) "_start:\n" \
            ".incbin \"" file "\"\n" \
            \
            ".global incbin_" STR(name) "_end\n" \
            ".balign 1\n" \
            "incbin_" STR(name) "_end:\n" \
            ".byte 0\n" \
    ); \
    extern __attribute__((aligned(16))) const char incbin_ ## name ## _start[]; \
    extern                              const char incbin_ ## name ## _end[]
INCBIN(device_tree, "/host/mk-manifest/microkit/example/maaxboard/hello/maaxboard.dtb"); 

char* _end = &incbin_device_tree_end;

#define REG_TIMER_PATH      "/soc@0/bus@30400000/timer@306a0000"
#define REG_CCM_PATH        "/soc@0/bus@30000000/clock-controller@30380000"
#define REG_IOMUXC_PATH     "/soc@0/bus@30000000/iomuxc@30330000"
#define REG_OCOTP_PATH      "/soc@0/bus@30000000/ocotp-ctrl@30350000"
#define REG_SYSCON_PATH     "/soc@0/bus@30000000/syscon@30360000"
#define REG_ETH_PATH        "/soc@0/bus@30800000/ethernet@30be0000"
#define REG_GPIO_PATH        "/soc@0/bus@30000000/gpio@30200000"

#define REG_PATH_COUNT 7

#define REG_PATHS {                                                             \
    REG_ETH_PATH,                                                               \
    REG_TIMER_PATH,                                                             \
    REG_CCM_PATH,                                                               \
    REG_OCOTP_PATH,                                                             \
    REG_SYSCON_PATH,                                                            \
    REG_IOMUXC_PATH,                                                            \
    REG_GPIO_PATH,                                                              \
    };

#define DEV_TIMER_PATH      REG_TIMER_PATH
#define DEV_CCM_PATH        REG_CCM_PATH
#define DEV_IOMUXC_PATH     REG_IOMUXC_PATH
#define DEV_OCOTP_PATH      REG_OCOTP_PATH
#define DEV_SYSCON_PATH     REG_SYSCON_PATH
#define DEV_ETH_PATH        REG_ETH_PATH
#define DEV_GPIO_PATH       REG_GPIO_PATH
#define DEV_CLK_1_PATH      "/clock-ckil"
#define DEV_CLK_2_PATH      "/clock-osc-25m"
#define DEV_CLK_3_PATH      "/clock-osc-27m"
#define DEV_CLK_4_PATH      "/clock-ext1"
#define DEV_CLK_5_PATH      "/clock-ext2"
#define DEV_CLK_6_PATH      "/clock-ext3"
#define DEV_CLK_7_PATH      "/clock-ext4"

#define DEV_PATH_COUNT 14

#define DEV_PATHS {                                                             \
    DEV_ETH_PATH,                                                               \
    DEV_TIMER_PATH,                                                             \
    DEV_CCM_PATH,                                                               \
    DEV_OCOTP_PATH,                                                             \
    DEV_SYSCON_PATH,                                                            \
    DEV_IOMUXC_PATH,                                                            \
    DEV_CLK_1_PATH,                                                             \
    DEV_CLK_2_PATH,                                                             \
    DEV_CLK_3_PATH,                                                             \
    DEV_CLK_4_PATH,                                                             \
    DEV_CLK_5_PATH,                                                             \
    DEV_CLK_6_PATH,                                                             \
    DEV_CLK_7_PATH                                                              \
    };

// picolibc setup
seL4_IPCBuffer* __sel4_ipc_buffer_obj;

uintptr_t heap_base;

int __ashlti3(int a, int b) {
    return a << b;
}

int __lshrti3(int a, int b) {
    return a >> b;
}


void
init(void)
{
    printf("hello, world printf style\n");

    // printf("start = %p\n", &incbin_device_tree_start);
    // printf("end = %p\n", &incbin_device_tree_end);
    // printf("size = %zu\n", (char*)&incbin_device_tree_end - (char*)&incbin_device_tree_start);
    // printf("first byte = 0x%02hhx\n", incbin_device_tree_start[0]);

    const char *const_reg_paths[] = REG_PATHS;
    const char *const_dev_paths[] = DEV_PATHS;
    // initialise uboot library
    initialise_uboot_drivers(
    &incbin_device_tree_start,
    /* List the device tree paths that need to be memory mapped */
    const_reg_paths, REG_PATH_COUNT,
    /* List the device tree paths for the devices */
    const_dev_paths, DEV_PATH_COUNT);
}

void
notified(microkit_channel ch)
{
}