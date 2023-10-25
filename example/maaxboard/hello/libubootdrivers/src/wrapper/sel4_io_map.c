/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

#include <io.h>

#define MAX_IO_MAPS 64

struct io_mapping_t {
    bool in_use;
    void *vaddr;
    uintptr_t paddr;
    size_t size;
};

static struct io_mapping_t io_mapping[MAX_IO_MAPS];

static ps_io_mapper_t *sel4_io_mapper = NULL;


static int next_free_allocation_index(void)
{
    for (int x = 0; x < MAX_IO_MAPS; x++)
        if (!io_mapping[x].in_use) return x;
    return -1;
}

static int find_allocation_index_by_vaddr(void *vaddr)
{
    for (int x = 0; x < MAX_IO_MAPS; x++)
        if (io_mapping[x].in_use && io_mapping[x].vaddr == vaddr) return x;
    return -1;
}

void sel4_io_map_do_unmap(void *vaddr)
{
    assert(sel4_io_mapper != NULL);

    // Find the previous allocation.
    int alloc_index = find_allocation_index_by_vaddr(vaddr);
    if (alloc_index < 0)
    {
        ZF_LOGE("Call to free mapped address not in bookkeeping");
        return;
    }

    ZF_LOGD("vaddr = %p, alloc_index = %i", vaddr, alloc_index);

    sel4_io_mapper->io_unmap_fn(
        sel4_io_mapper->cookie,
        io_mapping[alloc_index].vaddr,
        io_mapping[alloc_index].size);

    // Memory allocated and pinned. Update bookkeeping.
    io_mapping[alloc_index].in_use = false;
    io_mapping[alloc_index].vaddr = 0;
    io_mapping[alloc_index].paddr = 0;
    io_mapping[alloc_index].size = 0;
}

void* sel4_io_map_do_map(uintptr_t paddr, size_t size)
{
    assert(sel4_io_mapper != NULL);

    int alloc_index = next_free_allocation_index();
    if (alloc_index < 0)
    {
        ZF_LOGE("No free io mapping slots, unable to map address range");
        return NULL;
    }

    void* vaddr = sel4_io_mapper->io_map_fn(
        sel4_io_mapper->cookie,
        paddr,
        size,
        0, /* Not cached */
        PS_MEM_NORMAL);
    if (vaddr == NULL)
    {
        ZF_LOGE("io_map allocation returned null pointer");
        return NULL;
    }

    ZF_LOGD("size = 0x%x, paddr = %p, vaddr = %x.", size, paddr, vaddr);

    // Memory allocated and pinned. Update bookkeeping.
    io_mapping[alloc_index].in_use = true;
    io_mapping[alloc_index].vaddr = vaddr;
    io_mapping[alloc_index].paddr = paddr;
    io_mapping[alloc_index].size = size;

    return vaddr;
}

void *sel4_io_map_virt_to_phys(void *vaddr)
{
    assert(sel4_io_mapper != NULL);

    // Find the allocation containing this address.
    int alloc_index = -1;
    for (int x = 0; x < MAX_IO_MAPS; x++)
        if (io_mapping[x].in_use &&
            vaddr >= io_mapping[x].vaddr &&
            vaddr < io_mapping[x].vaddr + io_mapping[x].size)
            {
                alloc_index = x;
                break;
            }
    if (alloc_index < 0)
    {
        ZF_LOGE("Unable to determine physical address from virtual %p", vaddr);
        for (int y = 0; y < MAX_IO_MAPS; y++)
            if (io_mapping[y].in_use)
                ZF_LOGE(" --> Index %i: vaddr = %p, size = 0x%x",
                    y, io_mapping[y].vaddr, io_mapping[y].size);
        /* This is a fatal error. Not being able to determine an address
         * indicates that we are attempting to communicate with a mapped
         * device via addresses that has not been mapped into the physical
         * address space. This implies that additional data needs to be
         * mapped. */
        assert(false);
    }

    // Return the translated address
    return (void*) io_mapping[alloc_index].paddr +
        (vaddr - io_mapping[alloc_index].vaddr);
}

void *sel4_io_map_phys_to_virt(void *paddr)
{
    assert(sel4_io_mapper != NULL);

    // Find the allocation containing this address.
    int alloc_index = -1;
    for (int x = 0; x < MAX_IO_MAPS; x++)
        if (io_mapping[x].in_use &&
            (uintptr_t)paddr >= io_mapping[x].paddr &&
            (uintptr_t)paddr < io_mapping[x].paddr + io_mapping[x].size)
            {
                alloc_index = x;
                break;
            }
    if (alloc_index < 0)
    {
        ZF_LOGE("Unable to determine virtual address from physical %p", paddr);
        /* This is a fatal error. Not being able to determine an address
         * indicates that we are attempting to communicate with a mapped
         * device via addresses that has not been mapped into the physical
         * address space. This implies that additional data needs to be
         * mapped. */
        assert(false);
    }

    // Return the translated address
    return (uintptr_t) io_mapping[alloc_index].vaddr +
        (paddr - io_mapping[alloc_index].paddr);
}

bool sel4_io_map_is_paddr_mapped(void *paddr)
{
    assert(sel4_io_mapper != NULL);

    // Find the allocation containing this address.
    int alloc_index = -1;
    for (int x = 0; x < MAX_IO_MAPS; x++)
        if (io_mapping[x].in_use &&
            (uintptr_t) paddr >= io_mapping[x].paddr &&
            (uintptr_t) paddr < io_mapping[x].paddr + io_mapping[x].size)
                return true;
    return false;
}

void sel4_io_map_initialise(ps_io_mapper_t *io_mapper)
{
    sel4_io_mapper = io_mapper;

    for (int x = 0; x < MAX_IO_MAPS; x++)
    {
        io_mapping[x].in_use = false;
        io_mapping[x].vaddr = NULL;
        io_mapping[x].paddr = 0;
        io_mapping[x].size = 0;
    }
}

void sel4_io_map_shutdown(void)
{
    // Unmap any current mappings.
    for (int x = 0; x < MAX_IO_MAPS; x++)
    {
        if (io_mapping[x].in_use)
            sel4_io_map_do_unmap(io_mapping[x].vaddr);
    }

    // Clear the pointer to the io_map routines.
    sel4_io_mapper = NULL;
}