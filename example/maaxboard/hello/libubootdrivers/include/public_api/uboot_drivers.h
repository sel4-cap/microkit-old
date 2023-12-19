/*
 * Copyright 2022, Capgemini Engineering
 *
 * SPDX-License-Identifier: BSD-2-Clause
 * 
 */

// #include <sel4platsupport/io.h>

/*
 * initialise_uboot_drivers() - initialise the u-boot driver library.
 *
 * This must be called before any other interface exported by the library.
 *
 * @io_ops: the thread's platform support IO operations
 * @reg_paths: list device tree paths with 'reg' entries to memory map
 * @reg_count: the length of the reg_paths list
 * @dev_paths: list device tree paths of devices to handle
 * @dev_count: the length of the dev_paths list
 *
 * Return: 0 if OK, otherwise failure.
 */

int initialise_uboot_drivers(
    const char *orig_fdt_blob,
    const char **reg_paths,
    uint32_t reg_count,
    const char **dev_paths,
    uint32_t dev_count);

/**
 * run_uboot_command() - executes a u-boot command as if entered at the
 *   u-boot command prompt
 *
 * @cmd: the command string
 *
 * Return: 0 if OK, otherwise failure.
 */
int run_uboot_command(char* cmd);

/**
 * uboot_monotonic_timer_get_us() - returns the time in microseconds from
 *   the monotonic timer.
 *
 * Return: Elapsed time in microseconds.
 */
unsigned long uboot_monotonic_timer_get_us(void);

/**
 * uboot_stdin_tstc() - tests whether a character is available to read from
 *   u-boot's stdin.
 *
 * This routine can be used to capture data from a device mapped to u-boot's
 * stdin file, for example a USB keyboard.
 *
 * Return: 0 if no character is available, 1 otherwise.
 */
int uboot_stdin_tstc();

/**
 * uboot_stdin_tstc() - returns the next character available to read from
 *   u-boot's stdin. If no character is currently available this routine
 *   will block. To prevent blocking the uboot_stdin_tstc function should
 *   be used to determine whether a character is available.
 *
 * Return: The character.
 */
int uboot_stdin_getc();

/**
 * uboot_eth_init() - Initialise ethernet. Must be called prior to other
 *    u_boot_eth_xxx routines.
 *
 * Return: 0 if OK, otherwise failure.
 */
int uboot_eth_init(void);

/**
 * uboot_eth_halt() - Halts ethernet, the opposite of uboot_eth_init.
 *    Once halted the uboot_eth_init must again be called before other
 *    u_boot_eth_xxx routines.
 *
 * Return: 0 if OK, otherwise failure.
 */
void uboot_eth_halt(void);

/**
 * uboot_eth_send() - Send an ethernet packet.
 *
 * @packet: pointer to the buffer to send.
 * @length: length of the buffer to send.
 *
 * Return: Return: 0 if OK, otherwise failure.
 */
int uboot_eth_send(unsigned char *packet, int length);

/**
 * uboot_eth_receive() - Receive an ethernet packet.
 *
 * @packet: pointer to the allocated buffer. The buffer must be free'd by
 *    calling uboot_eth_free_packet. Note this paramter is only valid
 *    when the return code is positive.
 *
 * Return: negative on error, 0 if no packet available, otherwise returns
 *    the length of the received packet.
 */
int uboot_eth_receive(unsigned char **packet);

/**
 * uboot_eth_free_packet() - Frees a packet buffer previously allocated
 *    through a call to uboot_eth_receive.
 *
 * @packet: pointer to the allocated buffer. The buffer must be free'd by
 *    calling uboot_eth_free_packet. Note this paramter is only valid
 *    when the return code is positive.
 *
 * Return: negative on error, 0 if no packet available, otherwise returns
 *    the length of the received packet.
 */
int uboot_eth_free_packet(unsigned char **packet);

/**
 * uboot_eth_get_ethaddr() - Return the MAC address.
 *
 * Return: A pointer to the 6 byte MAC address.
 */
unsigned char *uboot_eth_get_ethaddr(void);

/**
 * shutdown_uboot_drivers() - shutdown the u-boot driver library.
 */
void shutdown_uboot_drivers(void);

