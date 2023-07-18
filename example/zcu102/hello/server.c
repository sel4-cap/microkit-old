/*
 * Copyright 2021, Breakaway Consulting Pty. Ltd.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include <stdint.h>
#include <sel4cp.h>

// Variables to store a very basic queue implementation
uint64_t protected_resoucre[100];
int head = 0;
int tail = 0;

// Add a number to the queue
void enqueue(uint64_t n) {
    protected_resoucre[head] = n;
    head ++;
    // sel4cp_dbg_puts("enqueue!\n");
}

// Remove a number form the queue
uint64_t dequeue() {
    if (head == tail){
        return 0; // zero represents an empty queue
    }
    uint64_t n = protected_resoucre[tail];
    tail++;
    // sel4cp_dbg_puts("dequeue!\n");
    return n;
}

void
init(void)
{
    sel4cp_dbg_puts("Server started!\n");
}

sel4cp_msginfo 
protected(sel4cp_channel ch, sel4cp_msginfo msginfo)
{
    switch (ch) {
        case 0:
            // sel4cp_dbg_puts("rpc call received from producer\n");
            enqueue(sel4cp_msginfo_get_label(msginfo)); // message info label is the int to be added to queue
            // notified(0);
            break;
        case 1:
            ; // seems to be a weird quirk that a declaration can't be the first line of a case statement????
            // sel4cp_dbg_puts("rpc call received from consumer\n");
            uint64_t n = dequeue();
            if (n!=0){
                // The first arg is the data we actually return. In this case it is an int but it may be a pointer
                // Other args are capability related so don't worry about them
                return seL4_MessageInfo_new(n, 0, 0, 0);
            }
            break;
        default:
            sel4cp_dbg_puts("server: received an unexpected message\n");
    }
    return seL4_MessageInfo_new(0, 0, 0, 0); 
}


// Server is set to passive in hello.system so can't receive notifications as it has no scheduling context of it's own
// Bizarly seems to fail compilation if commented out, even though calling it from another PD will crash it???
void
notified(sel4cp_channel ch)
{
    // ch corresponds to channel id in .system file
    switch (ch) {
        case 0:
            sel4cp_dbg_puts("Server notified by consumer\n");
            break;
        case 1:
            sel4cp_dbg_puts("Server notified by producer\n");
            break;
        default:
            seL4_Assert(0); // should never be called
    }
}