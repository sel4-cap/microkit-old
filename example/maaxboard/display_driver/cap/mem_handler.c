/* This work is Crown Copyright NCSC, 2023. */
#include <microkit.h>
#include <printf.h>
#include <tinyalloc.h>

uintptr_t heap_base;
uint64_t heap_size = 0x2000000;
int ta_blocks = 1024;
int ta_thresh = 16;
int ta_align = 64;
uintptr_t ta_limit;

void
init(void) {
    ta_limit = heap_base + heap_size;
    printf("INFO: heap from %p to %p\n", heap_base, ta_limit);
    bool error = ta_init((void*)heap_base, (void*)ta_limit, ta_blocks, ta_thresh, ta_align);
    printf("PD Mem_handler init OK\n");
}


void
notified(microkit_channel ch) {
}

microkit_msginfo
protected(microkit_channel ch, microkit_msginfo msginfo) {
    switch (ch) {
        case 0:
        case 5:
        case 10:
        case 20:
            return seL4_MessageInfo_new((uint64_t) ta_alloc(microkit_msginfo_get_label(msginfo)),1,0,0);
            break;
        case 1:
        case 6:
        case 11:
        case 21:
            return seL4_MessageInfo_new((uint64_t) ta_calloc(microkit_msginfo_get_label(msginfo), 1), 1, 0, 0);
            break;
        case 2:
        case 7:
        case 12:
        case 22:
            return seL4_MessageInfo_new(ta_free((void*)microkit_msginfo_get_label(msginfo)), 1, 0, 0);
            break;
        default:
            printf("Unexpected channel mem_handler %d\n", ch);
    }
}
