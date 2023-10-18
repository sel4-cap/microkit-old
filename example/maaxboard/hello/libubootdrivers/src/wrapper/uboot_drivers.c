/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * This file performs all of the initialisation and shutdown of the library
 * required from within the seL4 'world', i.e. those actions that require
 * use of seL4 libraries such as mapping of the physical memory for the
 * devices to be used.
 *
 * Following successful initialisation within this file the 'uboot_wrapper'
 * is called to continue within the U-Boot 'world'.
 */

#include <sel4platsupport/io.h>

#include <libfdt.h>
#include <uboot_wrapper.h>
#include <utils/page.h>

// The amount of extra space (in bytes) provided to our copy of the FDT to
// allow sufficient space for modifications.
#define EXTRA_FDT_BUFFER_SIZE 1024 * 8;

// Pointer to the FDT.
static void* uboot_fdt_pointer = NULL;


static int get_node_size_and_address_data(uintptr_t *addr, size_t *size, int *addr_cells, int *size_cells, int node_offset) {
    // Get the name of the path for logging purposes.
    const char *path_name = fdt_get_name(uboot_fdt_pointer, node_offset, NULL);

    // Get the offset of the parent node (need to query for cell sizes).
    int parent_node_offset = fdt_parent_offset(uboot_fdt_pointer, node_offset);
    if (parent_node_offset < 0) {
        ZF_LOGD("Unable to find parent of path '%s' in device tree.", path_name);
        return node_offset;
    }

    // Read the number of address and size cells used (from the parent node).
    *addr_cells = fdt_address_cells(uboot_fdt_pointer, parent_node_offset);
    if (*addr_cells < 1 || *addr_cells > 2) {
        ZF_LOGD("Path '%s' has address other than 32 or 64 bits.", path_name);
        return -1;
    }

    *size_cells = fdt_size_cells(uboot_fdt_pointer, parent_node_offset);
    if (*size_cells < 1 || *size_cells > 2) {
        ZF_LOGD("Path '%s' has size other than 32 or 64 bits.", path_name);
        return -1;
    }

    // Read the 'reg' property.
    int prop_len;
    const struct fdt_property *reg_property;
    reg_property = fdt_get_property(uboot_fdt_pointer, node_offset, "reg", &prop_len);
    if (reg_property == NULL) {
        ZF_LOGD("Path '%s' had no 'reg' property in device tree.", path_name);
        return prop_len;
    }

    // Make sure there is only a single address / size pair in the 'reg' property.
    if ((*addr_cells + *size_cells) * 4 != prop_len) {
        ZF_LOGD("Path '%s' has 'reg' property consisting of more than a single address, size pair. Unhandled.", path_name);
        return -1;
    }

    // Determine the address and size.
    if (*addr_cells == 2)
        *addr = (uintptr_t) fdt64_to_cpu(*(fdt64_t *) &reg_property->data[0]);
    else
        *addr = (uintptr_t) fdt32_to_cpu(*(fdt32_t *) &reg_property->data[0]);

    if (*size_cells == 2)
        *size = (size_t) fdt64_to_cpu(*(fdt64_t *) &reg_property->data[4 * *addr_cells]);
    else
        *size = (size_t) fdt32_to_cpu(*(fdt32_t *) &reg_property->data[4 * *addr_cells]);

    return 0;
}

static int map_device_resources(const char* path) {

    // Lookup the address and size information form the memory mapped device.
    int node_offset = fdt_path_offset(uboot_fdt_pointer, path);
    if (node_offset < 0) {
        ZF_LOGE("Unable to find path '%s' in device tree.\n", path);
        return -1;
    }

    // Find the address and size of the device (if it has a 'reg' property)
    uintptr_t paddr;
    size_t size;
    int addr_cells;
    int size_cells;
    int ret = get_node_size_and_address_data(&paddr, &size, &addr_cells, &size_cells, node_offset);
    if (0 != ret) {
        ZF_LOGD("Unable to read 'reg' property for path '%s' from device tree.", path);
        return 0;
    }

    // We now have a known and verified address and size for the device.
    // Map it into our virtual address space. Note that the address must
    // be on a 4K boundary to be accepted, this is achieved by rounding
    // the address to the nearest 4K boundary and increasing the size to
    // compensate.
    uintptr_t unaligned_paddr = paddr;
    paddr = PAGE_ALIGN_4K(paddr);
    assert(paddr <= unaligned_paddr);
    size = size + (unaligned_paddr - paddr);

    uintptr_t vaddr = (uintptr_t) sel4_io_map_do_map(paddr, size);
    if (0 == vaddr) {
        ZF_LOGE("Unable to map virtual address for path '%s'.", path);
        return -1;
    }

    ZF_LOGD("Mapped '%s' of size 0x%x from paddr %p to vaddr %x.", path, size, paddr, vaddr);

    return 0;
}

static int map_required_device_resources(const char **device_paths, uint32_t device_count)
{
    // Allocate resources and modify addresses in the device tree for each device.
    for (int dev_index=0; dev_index < device_count; dev_index++) {
        if (map_device_resources(device_paths[dev_index]) != 0) {
            free(uboot_fdt_pointer);
            uboot_fdt_pointer = NULL;
            return -1;
        }
    }

    return 0;
}

static int set_parent_status(int current_node, char *status_to_set)
{
    // Set status of this node.
    int err = fdt_setprop_string(uboot_fdt_pointer, current_node, "status", status_to_set);
    if (err != 0) {
        ZF_LOGE("Failed to set 'status' with error %i. Buffer not big enough?", err);
        return -1;
    };

    // Now set status of parent
    int parent_node = fdt_parent_offset(uboot_fdt_pointer, current_node);
    if (parent_node >= 0)
        if (set_parent_status(parent_node, status_to_set) != 0)
            return -1;

    return 0;
}

static int set_all_child_status(int parent_node, char *status_to_set)
{
    // Set status of this node.
    int err = fdt_setprop_string(uboot_fdt_pointer, parent_node, "status", status_to_set);
    if (err != 0) {
        ZF_LOGE("Failed to set 'status' with error %i. Buffer not bid enough?", err);
        return -1;
    };

    // Now set status of all children
    int child_node;
    fdt_for_each_subnode(child_node, uboot_fdt_pointer, parent_node)
        if (set_all_child_status(child_node, status_to_set) != 0)
            return -1;

    return 0;
}

static int disable_not_required_devices(const char **device_paths, uint32_t device_count)
{
    // Start off by recursively disabling all devices in the device tree
    if (set_all_child_status(fdt_path_offset(uboot_fdt_pointer, "/"), "disabled") != 0)
        return -1;

    // Now set the status for all parents and children (recursively) of our used
    // devices to 'okay'. This leaves only the minimum set of devices enabled
    // which we actually require.
    for (int dev_index=0; dev_index < device_count; dev_index++) {
        if (set_parent_status(fdt_path_offset(uboot_fdt_pointer, device_paths[dev_index]), "okay") != 0)
            return -1;
        if (set_all_child_status(fdt_path_offset(uboot_fdt_pointer, device_paths[dev_index]), "okay") != 0)
            return -1;
    }

    return 0;
}

int initialise_uboot_drivers(
    ps_io_ops_t *io_ops,
    const char **reg_paths,
    uint32_t reg_count,
    const char **dev_paths,
    uint32_t dev_count)
{
    // Return immediately if no devices have been requested.
    if (0 == reg_count || NULL == reg_paths || 0 == dev_count || NULL == dev_paths) {
        ZF_LOGE("Library initialisation cancelled, no devices supplied");
        return -1;
    }

    int ret;

    // Initialise the DMA management.
    sel4_dma_initialise(&io_ops->dma_manager);

    // Initialise the IO mapping management.
    sel4_io_map_initialise(&io_ops->io_mapper);

    // Create a copy of the FDT for U-Boot to use. We do this using
    // 'fdt_open_into' to open the FDT into a larger buffer to allow
    // us extra space to make modifications as required.
    void* orig_fdt_blob = ps_io_fdt_get(&io_ops->io_fdt);
    if (orig_fdt_blob == NULL) {
        ZF_LOGE("Unable to access FDT");
        return -1;
    }

    int fdt_size = fdt_totalsize(orig_fdt_blob) + EXTRA_FDT_BUFFER_SIZE;
    uboot_fdt_pointer = malloc(fdt_size);
    if (uboot_fdt_pointer == NULL) {
        return -ENOMEM;
    }
    ret = fdt_open_into(orig_fdt_blob, uboot_fdt_pointer, fdt_size);
    if (0 != ret)
        goto error;

    // Start by disabling all devices in the FDT that are not required.
    ret = disable_not_required_devices(dev_paths, dev_count);
    if (0 != ret)
        goto error;

    // Map the required device resources for all required devices.
    ret = map_required_device_resources(reg_paths, reg_count);
    if (0 != ret)
        goto error;

    // Start the U-Boot wrapper. Provide it a pointer to the FDT blob.
    ret = initialise_uboot_wrapper(uboot_fdt_pointer);
    if (0 != ret)
        goto error;

    // All done.
    return 0;

error:
    // Failed to initialise library, clean up and return error code.
    free(uboot_fdt_pointer);
    uboot_fdt_pointer = NULL;
    return -1;
}

void shutdown_uboot_drivers(void) {
    if (uboot_fdt_pointer != NULL) {
        free(uboot_fdt_pointer);
        uboot_fdt_pointer = NULL;
    }

    shutdown_uboot_wrapper();

    sel4_io_map_shutdown();

    sel4_dma_shutdown();
}