//  * Copyright 2021, Breakaway Consulting Pty. Ltd.
//  *
//  * SPDX-License-Identifier: BSD-2-Clause
//  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
// #include <assert.h>
#include <errno.h>
#include <microkit.h>

seL4_IPCBuffer* __sel4_ipc_buffer_obj;

uintptr_t heap_base;
uintptr_t __heap_start;
uintptr_t __heap_end;

/* Setup for getting printf functionality working */
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

char buf[20];
char *hello = "hello world!\n";

void
init(void)
{

    microkit_dbg_puts("hello, world\n");
    // strlen("hello\n");

    // microkit_dbg_puts("calling atoi on 'a': ");
    // int x = atoi("a");
    // microkit_dbg_putc(x);
    // microkit_dbg_putc('\n');

    // memcpy(buf, hello, strlen(hello));
    // microkit_dbg_puts(buf);

    // printf("hello from printf!\n");

    // // printf("INFO: __heap_start: 0x%lx, __heap_end: 0x%lx, size of heap: 0x%lx\n", (uintptr_t)__heap_start,(uintptr_t)__heap_end,(uintptr_t)(__heap_end - __heap_start));
    // // assert(__heap_end - __heap_start == HEAP_SIZE);
    // printf("INFO: trying to malloc\n");
    // char *mallocd_ptr3 = malloc(strlen(hello) * 1000);
    // if (!mallocd_ptr3) {
    //     printf("???\n");
    //     printf("ERROR: malloc returned NULL with errno %s\n", strerror(errno));
    //     return;
    // }
    // printf("here\n");
    // printf("%p\n", mallocd_ptr3);
    // memcpy(mallocd_ptr3, hello, strlen(hello));

    // for (int i = 0; i < strlen(hello); i++){
    //     printf("%c\n", mallocd_ptr3[i]);
    // }

    // free(mallocd_ptr3);

    // char *mallocd_ptr4 = malloc(strlen(hello));
    // printf("%p\n", mallocd_ptr4);

    // Intentionally call assert with a false value in order to see that the
    // assert fail functionality works
    // assert(0);
}

void
notified(microkit_channel ch)
{
    // switch (ch) {
    //     case 0:
    //         for (int i = 0; i < strlen(hello); i++){
    //             printf("%c\n", mallocd_ptr[strlen(hello) -i]);
    //         }
    // }
}
