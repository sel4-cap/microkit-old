/* This work is Crown Copyright NCSC, 2023. */
#include <microkit.h>
#include <printf.h>

#include <sys/kmem.h>

uintptr_t keyboard_base;
uintptr_t ta_limit;
char* kbd_mem_write;

void
init(void) {
    printf("simulated_kbd init\n");
}

void
notified(microkit_channel ch) {
    printf("simulated_kbd notified\n");
}


microkit_msginfo
protected(microkit_channel ch, microkit_msginfo msginfo) {
    switch (ch) {
        case 14:
            kbd_mem_write = (char*) microkit_msginfo_get_label(msginfo);
            *kbd_mem_write = 'A';
            microkit_notify(15);
            break;
        default:
            printf("kbd_logger received protected unexpected channel\n");
    }
    return seL4_MessageInfo_new(0,0,0,0);
}