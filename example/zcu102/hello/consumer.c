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

// continuously try to check for available resources
void busyWait(){
    while(1) {
        sel4cp_msginfo info = sel4cp_ppcall(1, sel4cp_msginfo_new(0, 1));
        uint64_t n = sel4cp_msginfo_get_label(info);

        if (n!=0){
            sel4cp_dbg_puts("Consumer: ");
            puthex64(n);
            sel4cp_dbg_puts("\n");
        } 
    } 
}

// helper function reteives a number from the server
void dequeue_single(){
    sel4cp_msginfo info = sel4cp_ppcall(1, sel4cp_msginfo_new(0, 1));
        uint64_t n = sel4cp_msginfo_get_label(info);

        if (n!=0){ // zero means the queue was empty
            sel4cp_dbg_puts("Consumer retreived: ");
            puthex64(n);
            sel4cp_dbg_puts("\n");
        } 
}

void
init(void)
{
    sel4cp_dbg_puts("Consumer started!\n");

    
    sel4cp_dbg_puts("yielded once\n");
    seL4_Yield(); // testing that the yield command can be used to allow another PD to run
    sel4cp_dbg_puts("yielded twice\n");

    // busyWait();
    // while(1){
    //     ;
    // }
}

void
notified(sel4cp_channel ch)
{
        switch (ch) {
        case 2:
            // sel4cp_dbg_puts("Consumer notified by producer\n");
            dequeue_single();
            sel4cp_notify(2);
            break;
        default:
            seL4_Assert(0); // should never be called
    }
}