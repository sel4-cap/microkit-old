/*
 * Copyright 2021, Breakaway Consulting Pty. Ltd.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include <stdint.h>
#include <microkit.h>
#include <printf.h>

void
init(void)
{
    printf("hello, world printf style\n");
}

void
notified(microkit_channel ch)
{
}