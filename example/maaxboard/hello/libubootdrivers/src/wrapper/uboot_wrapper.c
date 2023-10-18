/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

#include <uboot_helper.h>
#include <dm/root.h>
#include <dm/util.h>
#include <usb.h>
#include <asm/global_data.h>
#include <fdtdec.h>
#include <of_live.h>
#include <driver_data_limits.h>
#include <driver_data.h>
#include <stdio_dev.h>
#include <console.h>
#include <mmc.h>
#include <net.h>
#include <env.h>
#include <command.h>
#include <sel4_timer.h>

// Global declaration of global_data.
struct global_data* gd;

// Global declaration of driver_data.
struct driver_data_t driver_data;

// Global declaration and initialisation of driver_data_start/end.
const struct driver_data_pointer_t driver_data_start = {
    .driver_start = driver_data.driver_array,
    .uclass_driver_start = driver_data.uclass_driver_array,
    .usb_driver_entry_start = driver_data.usb_driver_entry_array,
    .cmd_start = driver_data.cmd_array,
    .part_driver_start = driver_data.part_driver_array,
    .env_driver_start = driver_data.env_driver_array,
    .env_clbk_start = driver_data.env_clbk_array,
    .driver_info_start = driver_data.driver_info_array,
    .udevice_start = driver_data.udevice_array
};

const struct driver_data_pointer_t driver_data_end = {
    .driver_start = &driver_data.driver_array[_u_boot_driver_count],
    .uclass_driver_start = &driver_data.uclass_driver_array[_u_boot_uclass_driver_count],
    .usb_driver_entry_start = &driver_data.usb_driver_entry_array[_u_boot_usb_driver_entry_count],
    .cmd_start = &driver_data.cmd_array[_u_boot_cmd_count],
    .part_driver_start = &driver_data.part_driver_array[_u_boot_part_driver_count],
    .env_driver_start = &driver_data.env_driver_array[_u_boot_env_driver_count],
    .env_clbk_start = &driver_data.env_clbk_array[_u_boot_env_clbk_count],
    .driver_info_start = &driver_data.driver_info_array[_u_boot_driver_info_count],
    .udevice_start = &driver_data.udevice_array[_u_boot_udevice_count]
};

// Global declaration of version_string.
const char version_string[] = "seL4 U-Boot driver";

// Global declaration and initialisation of the default load address.
ulong image_load_addr = CONFIG_SYS_LOAD_ADDR;

// State determining whether the library has been initialised.
static bool library_initialised = false;

int initialise_uboot_wrapper(char* fdt_blob)
{
    // Start the monotonic timer.
    initialise_and_start_timer();

    // Return immediately if already initialised (nothing to do).
    if (library_initialised) return 0;

    // Set up the driver data.
    initialise_driver_data();

    // Allocation of global_data.
    gd = malloc(sizeof(gd_t));
    if (gd == NULL)
        return -ENOMEM;

    // Initialisation of (unused sections of the) global_data.
    gd->bd = NULL;
    gd->flags = 0;
    gd->flags |= GD_FLG_RELOC;  /* Work as if u-boot has finished relocation to RAM */
    gd->baudrate = 0;
	gd->cpu_clk = 0;
	gd->bus_clk = 0;
	gd->pci_clk = 0;
	gd->mem_clk = 0;
    gd->have_console = 1;
	gd->ram_base = 0;
	gd->ram_top = 0;
	gd->relocaddr = 0;
	gd->ram_size = 0;
	gd->mon_len = 0;
	gd->irq_sp = 0;
	gd->start_addr_sp = 0;
	gd->reloc_off = 0;
	gd->new_gd = NULL;
    gd->jt = NULL;
    gd->env_buf[0] = '\n';
    gd->timebase_h = 0;
	gd->timebase_l = 0;
    gd->cur_serial_dev = NULL;

    // Initialisation of the DM specific parts of global_data.
    gd->dm_root = NULL;
    gd->dm_root_f = NULL;
	gd->uclass_root_s.next = NULL;
	gd->uclass_root_s.prev = NULL;
	gd->uclass_root = NULL;

    // Manually initialise of the FDT parts of global_data as if FDT handling
    // had been set up for an embedded FDT.
    gd->fdt_blob = fdt_blob;
	gd->new_fdt = NULL;
	gd->fdt_size = fdt_totalsize(fdt_blob);
	gd->fdt_src = FDTSRC_EMBED;

    // Build the live tree from the FDT.
    gd->of_root = NULL;
    int ret = of_live_build(gd->fdt_blob, (struct device_node **)gd_of_root_ptr());
    if (0 != ret)
        goto error;

    // Manually initialise the environment system. We do this by marking the
    // the pre-relocation environment as invalid, i.e. not present, and then
    // asking for the environment to be relocated to RAM. This will set up
    // the RAM with the default environment as a starting point.
    gd->env_addr = 0;
	gd->env_valid = ENV_INVALID;
	gd->env_has_init = 0;
	gd->env_load_prio = 0;
    env_relocate();

    // Initialise the stdio files / devices and the (stubbed) cosole.
    ret = stdio_init();
    if (0 != ret)
        goto error;
    ret = console_init_r();
    if (0 != ret)
        goto error;

    // Scan the device tree for compatible drivers.
    ret = dm_init_and_scan(false);
    if (0 != ret)
        goto error;

#ifdef CONFIG_DM_MMC
    // Initialize the MMC system.
    ret = mmc_initialize(NULL);
    if (0 != ret)
        goto error;
#endif

#ifdef CONFIG_NET
    // Initialize the ethernet system.
	puts("Net:   ");
	eth_initialize();
#ifdef CONFIG_RESET_PHY_R
	debug("Reset Ethernet PHY\n");
	reset_phy();
#endif
#endif

    // Success.
    library_initialised = true;
    return 0;

error:
    // Failed to initialise library, clean up and return error code.
    free(gd);
    gd = NULL;
    return -1;
}

int run_uboot_command(char* cmd)
{
    // Fail immediately if library not initialised.
    if (!library_initialised)
        return -1;

    log_info("--- running command '%s' ---", cmd);

    // Perform the command.
    int ret = run_command(cmd, CMD_FLAG_ENV);

    log_info("--- command '%s' completed with return code %i ---", cmd, ret);

    return ret;
}

void shutdown_uboot_wrapper(void)
{
    // Return immediately if library not initialised (nothing to do).
    if (!library_initialised)
        return;

    // Shutdown the monotonic timer.
    shutdown_timer();

    // Delete persistant state.
    free(gd);
    gd = NULL;

    return;
}

unsigned long uboot_monotonic_timer_get_us(void)
{
    return timer_get_us();
}

int uboot_stdin_tstc(void)
{
    // Return immediately if library not initialised .
    if (!library_initialised)
        return -1;

    if (NULL == stdio_devices[stdin])
        return 0;

    return stdio_devices[stdin]->tstc(stdio_devices[stdin]);
}

int uboot_stdin_getc(void)
{
    // Return immediately if library not initialised .
    if (!library_initialised)
        return -1;

    if (NULL == stdio_devices[stdin])
        return 0;

    return stdio_devices[stdin]->getc(stdio_devices[stdin]);
}

#ifdef CONFIG_DM_ETH

int uboot_eth_init(void)
{
    // Return immediately if library not initialised .
    if (!library_initialised)
        return -1;

    return eth_init();
}
void uboot_eth_halt(void)
{
    // Return immediately if library not initialised .
    if (!library_initialised)
        return;

    eth_halt();
}

int uboot_eth_send(unsigned char *packet, int length)
{
    // Return immediately if library not initialised .
    if (!library_initialised)
        return -1;

	struct udevice *current;
	int ret;

	current = eth_get_dev();
	if (!current)
		return -ENODEV;

	if (!eth_is_active(current))
		return -EINVAL;

	ret = eth_get_ops(current)->send(current, packet, length);

	return ret;
}

int uboot_eth_receive(unsigned char **packet)
{
    // Return immediately if library not initialised .
    if (!library_initialised)
        return -1;

	struct udevice *current;

	current = eth_get_dev();
	if (!current)
		return -ENODEV;

	if (!eth_is_active(current))
		return -EINVAL;

    int ret = eth_get_ops(current)->recv(current, ETH_RECV_CHECK_DEVICE, packet);

    if (ret == 0 && eth_get_ops(current)->free_pkt)
        eth_get_ops(current)->free_pkt(current, *packet, ret);

	if (ret == -EAGAIN)
		ret = 0;

	return ret;
}

int uboot_eth_free_packet(unsigned char **packet)
{
    // Return immediately if library not initialised .
    if (!library_initialised)
        return -1;

	struct udevice *current;
    int ret = 0;

	current = eth_get_dev();
	if (!current)
		return -ENODEV;

    if (eth_get_ops(current)->free_pkt)
        eth_get_ops(current)->free_pkt(current, *packet, ret);

	return ret;
}

unsigned char *uboot_eth_get_ethaddr(void)
{
    // Return immediately if library not initialised .
    if (!library_initialised)
        return 0;

    return eth_get_ethaddr();
}

#else

int uboot_eth_init(void) { return 0; }
void uboot_eth_halt(void) {}
int uboot_eth_send(unsigned char *packet, int length) { return 0; }
int uboot_eth_receive(unsigned char **packet) { return 0; }
int uboot_eth_free_packet(unsigned char **packet) { return 0; }
unsigned char *uboot_eth_get_ethaddr(void) { return 0; }

#endif