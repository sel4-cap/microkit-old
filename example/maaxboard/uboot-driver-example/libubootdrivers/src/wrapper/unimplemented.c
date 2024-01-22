/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

#include <uboot_helper.h>
#include <dm/device.h>

#include <linux/usb/gadget.h>
#include "../../uboot/drivers/usb/dwc3/core.h"

#include <input.h>

/* This is required to prevent a linker error but is never used (because OF_PLATDATA_INST is not defined) */
struct udevice _u_boot_udevice__root;

int common_diskboot(struct cmd_tbl *cmdtp, const char *intf, int argc,
		    char *const argv[])
{
    debug("Command not supported.");
}

// Console related routines.
int ctrlc(void) { return 0; }
int had_ctrlc(void) { return 0; }
void clear_ctrlc(void) {}
int disable_ctrlc(int file) { return 0; }

// Input and serial related routines.
extern void serial_stdio_init(void) {}
int input_tstc(struct input_config *config) { return 0; }
int input_getc(struct input_config *config) { return 0; }
int input_init(struct input_config *config, int leds) { return 0; }
void serial_putc(const char ch) { assert(false); }
void serial_puts(const char *str) { assert(false); }
int serial_getc(void)  { assert(false); }
int serial_tstc(void) { assert(false); }

/* Unused routines. Ensure they are not used by raising an assert */
long get_ram_size(long *base, long size) { assert(false); }
void *locate_dtb_in_fit(const void *fit) { assert(false); }
u32 dm_pci_read_bar32(const struct udevice *dev, int barnum) { assert(false); }
void dwc3_gadget_uboot_handle_interrupt(struct dwc3 *dwc)  { assert(false); }
int utf8_put(s32 code, char **dst) { assert(false); }
size_t utf16_strnlen(const u16 *src, size_t count) { assert(false); }
size_t utf16_utf8_strnlen(const u16 *src, size_t count) { assert(false); }
s32 utf16_get(const u16 **src) { assert(false); }
bool is_usb_boot(void) { assert(false); }