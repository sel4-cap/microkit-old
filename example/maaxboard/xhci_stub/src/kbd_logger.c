#include <sel4cp.h>
#include <printf.h>

#include <tinyalloc.h>

uintptr_t keyboard_base;

char* kbd_mem_write;
uintptr_t ta_limit;
uint64_t keyboard_size = 0x10000;
int ta_blocks = 256;
int ta_thresh = 16;
int ta_align = 64;

void
init(void) {
    printf("KBD_LOGGER\n");
    ta_limit = keyboard_base + keyboard_size;
    bool error = ta_init((void*)keyboard_base, (void*)ta_limit, ta_blocks, ta_thresh, ta_align);
    printf("Init malloc: %d\n", error);
    kbd_mem_write = ta_alloc(sizeof(char));
    printf("Sending memory address to be written to %p\n", kbd_mem_write);
    sel4cp_msginfo addr = sel4cp_ppcall(13, seL4_MessageInfo_new((uint64_t) kbd_mem_write,1,0,0));
}

void
notified(sel4cp_channel ch) {
    switch(ch) {
        case(16):
            ;
            // char data = *kbd_mem_write;
            printf("kbd_logger notified by similated_kbd. Data   : %c\n", *kbd_mem_write);
    }
}
