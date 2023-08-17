/*
 * Copyright 2022, UNSW
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "shared_ringbuffer.h"
#include "printf.h"

#include <dev/wscons/wsksymdef.h>

void ring_init(ring_handle_t *ring, ring_buffer_t *free, ring_buffer_t *used, notify_fn notify, int buffer_init)
{
    printf("ring init 1\n");
    ring->free_ring = free;
    printf("ring init 2\n");
    ring->used_ring = used;
    printf("ring init 3\n");
    ring->notify = notify;
    printf("ring init 4\n");

    if (buffer_init) {
        printf("ring init 5\n");
        ring->free_ring->write_idx = 0;
        printf("ring init 6\n");
        ring->free_ring->read_idx = 0;
        printf("ring init 7\n");
        ring->used_ring->write_idx = 0;
        printf("ring init 8\n");
        ring->used_ring->read_idx = 0;
        printf("ring init 9\n");
    }
}
