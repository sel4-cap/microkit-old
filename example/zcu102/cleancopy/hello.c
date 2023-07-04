/*
 * Copyright 2021, Breakaway Consulting Pty. Ltd.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include <stdint.h>
#include <sel4cp.h>

static char
hexchar(unsigned int v)
{
    return v < 10 ? '0' + v : ('a' - 10) + v;
}

static void
puthex64(uint64_t x)
{
    char buffer[19];
    buffer[0] = '0';
    buffer[1] = 'x';
    buffer[2] = hexchar((x >> 60) & 0xf);
    buffer[3] = hexchar((x >> 56) & 0xf);
    buffer[4] = hexchar((x >> 52) & 0xf);
    buffer[5] = hexchar((x >> 48) & 0xf);
    buffer[6] = hexchar((x >> 44) & 0xf);
    buffer[7] = hexchar((x >> 40) & 0xf);
    buffer[8] = hexchar((x >> 36) & 0xf);
    buffer[9] = hexchar((x >> 32) & 0xf);
    buffer[10] = hexchar((x >> 28) & 0xf);
    buffer[11] = hexchar((x >> 24) & 0xf);
    buffer[12] = hexchar((x >> 20) & 0xf);
    buffer[13] = hexchar((x >> 16) & 0xf);
    buffer[14] = hexchar((x >> 12) & 0xf);
    buffer[15] = hexchar((x >> 8) & 0xf);
    buffer[16] = hexchar((x >> 4) & 0xf);
    buffer[17] = hexchar(x & 0xf);
    buffer[18] = 0;
    sel4cp_dbg_puts(buffer);
}


// helper function to make the rpc call to the server
void queue_single(int n){
    // sel4cp_ppcall() needs a sel4 msg to encapsulate the argument (and capabilities etc we don't worry about)
    // sel4cp_ppcall() returns a sel4 msg info but we cast it to void here as we don't use it
    (void) sel4cp_ppcall(0, sel4cp_msginfo_new(n, 1));
    sel4cp_dbg_puts("Producer queued!");
    puthex64(n);
    sel4cp_dbg_puts("\n");
}

void
init(void)
{
    sel4cp_dbg_puts("Producer started!\n");

    // loop to add some numbers to the queue
    for (int i=1; i<6; i++){
        queue_single(i);   // RPC call to server, i is the uint64 arguement
        // (void) sel4cp_ppcall(0, sel4cp_msginfo_new(i, 1)); 
        sel4cp_notify(2); // notify the consumer after we have finished adding to queue
    }

    // we can call our own notified() if we wanted to (not sure if it would be useful as would act like a normal fn call)
    // notified(-1);
}

void
notified(sel4cp_channel ch)
{
    switch (ch) {
        case 2:
            // sel4cp_dbg_puts("Producer notified by consumer\n");
            break;
        default:
            seL4_Assert(0); // should never be called
    }
}