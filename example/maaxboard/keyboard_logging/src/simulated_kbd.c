#include <sel4cp.h>
#include <printf.h>

#include <sys/kmem.h>

uintptr_t keyboard_base;
uintptr_t ta_limit;
char* kbd_mem_write;

void
init(void) {
    printf("SIMULATED_KBD\n");
    // sel4cp_notify(15);
}

void
notified(sel4cp_channel ch) {
    printf("simulated_kbd notified");
}


sel4cp_msginfo
protected(sel4cp_channel ch, sel4cp_msginfo msginfo) {
    switch (ch) {
        case 14:
            printf("pp_call from kbd_logger\n");
            kbd_mem_write = (char*) sel4cp_msginfo_get_label(msginfo);
            printf("Received memory address from kbd_logger to write to: %p\n", kbd_mem_write);
            *kbd_mem_write = 'A';
            printf("kbd_logger notified by similated_kbd. Data   : %c\n", kbd_mem_write);
            sel4cp_notify(15);
            break;
        default:
            printf("kbd_logger received protected unexpected channel\n");
    }
    return seL4_MessageInfo_new(0,0,0,0);
}
