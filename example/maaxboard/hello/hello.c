/*
 * Copyright 2021, Breakaway Consulting Pty. Ltd.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include <stdint.h>
#include <microkit.h>
#include <printf.h>
#include <tinyalloc.h>
#include <dma.h>
#include <uboot_drivers.h>

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
INCBIN(device_tree, "/home/dstorer/mk-manifest/microkit/example/maaxboard/hello/maaxboard.dtb"); 

void
init(void)
{
    printf("hello, world printf style\n");

    printf("start = %p\n", &incbin_device_tree_start);
    printf("end = %p\n", &incbin_device_tree_end);
    printf("size = %zu\n", (char*)&incbin_device_tree_end - (char*)&incbin_device_tree_start);
    printf("first byte = 0x%02hhx\n", incbin_device_tree_start[0]);

    run_uboot_command("dm tree");
}

void
notified(microkit_channel ch)
{
}