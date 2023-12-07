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

// picolibc setup
seL4_IPCBuffer* __sel4_ipc_buffer_obj;

uintptr_t heap_base;

/* Setup for getting picolibc to compile */
static int
libc_microkit_putc(char c, FILE *file)
{
    (void) file; /* Not used by us */
    microkit_dbg_putc(c);
    return c;
}

static int
sample_getc(FILE *file)
{
	return -1; /* getc not implemented, return EOF */
}

static FILE __stdio = FDEV_SETUP_STREAM(libc_microkit_putc,
                    sample_getc,
                    NULL,
                    _FDEV_SETUP_WRITE);
FILE *const stdin = &__stdio; __strong_reference(stdin, stdout); __strong_reference(stdin, stderr);

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

    printf("start = %p\n", &incbin_device_tree_start);
    printf("end = %p\n", &incbin_device_tree_end);
    printf("size = %zu\n", (char*)&incbin_device_tree_end - (char*)&incbin_device_tree_start);
    printf("first byte = 0x%02hhx\n", incbin_device_tree_start[0]);

    // initialise tinyalloc
    //  initialise uboot library

    run_uboot_command("dm tree");
}

void
notified(microkit_channel ch)
{
}