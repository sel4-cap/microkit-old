#include <io.h>

// #include <platform_devices.h>

#include <wrapper.h>
#include <printf.h>
#include <tinyalloc.h>
// #include <sys/intr.h>
// #include <sys/systm.h>
// #include <sys/kernel.h>

#include <sel4dma.h>
#include <dma.h>


#include <dma-direction.h>

#define MAX_DMA_ALLOCS 256

struct dma_allocation_t {
    /* Base data for all DMA allocations */
    bool in_use;
    bool is_mapping;
    void *public_vaddr; /* The vaddr used outside of this file */
    void *mapped_vaddr; /* The vaddr that is mapped to the paddr */
    void *paddr;
    size_t size;
    /* Additional data relevant only to DMA mappings */
    enum dma_data_direction mapping_dir;
};

static struct dma_allocation_t dma_alloc[MAX_DMA_ALLOCS];

ps_dma_man_t *sel4_dma_manager = NULL;

static void clear_allocation_new(int alloc_index)
{
    dma_alloc[alloc_index].in_use = false;
    dma_alloc[alloc_index].is_mapping = false;
    dma_alloc[alloc_index].public_vaddr = NULL;
    dma_alloc[alloc_index].mapped_vaddr = NULL;
    dma_alloc[alloc_index].paddr = 0;
    dma_alloc[alloc_index].size = 0;
    dma_alloc[alloc_index].mapping_dir = DMA_NONE;
}

static int next_free_allocation_index(void)
{
    for (int x = 0; x < MAX_DMA_ALLOCS; x++)
        if (!dma_alloc[x].in_use) return x;
    return -1;
}

static int find_allocation_index_by_public_vaddr(void *addr)
{
    for (int x = 0; x < MAX_DMA_ALLOCS; x++) {
        if (dma_alloc[x].in_use &&
            dma_alloc[x].public_vaddr == addr &&
            dma_alloc[x].size == 0)
            return x;
        if (dma_alloc[x].in_use &&
            dma_alloc[x].public_vaddr <= addr &&
            dma_alloc[x].public_vaddr + dma_alloc[x].size > addr)
            return x;
    }
    return -1;
}

static int find_allocation_index_by_mapped_vaddr(void *addr)
{
    for (int x = 0; x < MAX_DMA_ALLOCS; x++) {
        if (dma_alloc[x].in_use &&
            dma_alloc[x].mapped_vaddr == addr &&
            dma_alloc[x].size == 0)
            return x;
        if (dma_alloc[x].in_use &&
            dma_alloc[x].mapped_vaddr <= addr &&
            dma_alloc[x].mapped_vaddr + dma_alloc[x].size > addr)
            return x;
    }
    return -1;
}

static int find_allocation_index_by_paddr(void *addr)
{
    for (int x = 0; x < MAX_DMA_ALLOCS; x++) {
        if (dma_alloc[x].in_use &&
            dma_alloc[x].paddr == addr &&
            dma_alloc[x].size == 0)
            return x;
        if (dma_alloc[x].in_use &&
            dma_alloc[x].paddr <= addr &&
            dma_alloc[x].paddr + dma_alloc[x].size > addr)
            return x;
    }
    return -1;
}

void* sel4_dma_memalign_new(size_t align, size_t size)
{
    printf("malloc dma\n");
    // assert(sel4_dma_manager != NULL);

    int alloc_index = next_free_allocation_index();
    if (alloc_index < 0) {
        // ZF_LOGE("No free DMA allocation slots, unable to allocate");
        printf("No free DMA allocation slots pointer\n");
        return NULL;
    }

    void* mapped_vaddr = sel4_dma_manager->dma_alloc_fn(
        sel4_dma_manager->cookie,
        size,
        align,
        false,
        PS_MEM_NORMAL);
    if (mapped_vaddr == NULL) {
        // ZF_LOGE("DMA allocation returned null pointer");
        printf("DMA allocation returned null pointer\n");
        return NULL;
    }

    void *paddr = (void*) sel4_dma_manager->dma_pin_fn(
        sel4_dma_manager->cookie,
        mapped_vaddr,
        size);
    if (paddr == NULL) {
        // ZF_LOGE("DMA pin return null pointer");
        printf("DMA pin returned null pointer\n");
        // Clean up before returning.
        sel4_dma_manager->dma_free_fn(
            sel4_dma_manager->cookie,
            mapped_vaddr,
            size);
        return NULL;
    }

    // ZF_LOGD(
        // "size = 0x%x, align = 0x%x, vaddr = %p, paddr = %p, alloc_index = %i",
        // size, align, mapped_vaddr, paddr, alloc_index);
    printf(
        "size = 0x%x, align = 0x%x, vaddr = %p, paddr = %p, alloc_index = %i\n",
        size, align, mapped_vaddr, paddr, alloc_index);

    // Memory allocated and pinned. Update bookkeeping.
    dma_alloc[alloc_index].in_use = true;
    dma_alloc[alloc_index].mapped_vaddr = mapped_vaddr;
    dma_alloc[alloc_index].public_vaddr = mapped_vaddr;
    dma_alloc[alloc_index].paddr = paddr;
    dma_alloc[alloc_index].size = size;
    // Not a mapping.
    dma_alloc[alloc_index].is_mapping = false;
    dma_alloc[alloc_index].mapping_dir = DMA_NONE;

    return mapped_vaddr;
}

void*	sel4_dma_dmaaddr(void *addr) {
    int err = find_allocation_index_by_mapped_vaddr(addr);
    if (err == -1) {
        printf("couldnt %x find by mapped vaddr\n", addr);
    } else {
        printf("found %x by mapped vaddr\n", addr);
        return dma_alloc[err].paddr;
    }
    err = find_allocation_index_by_public_vaddr(addr);
    if (err == -1) {
        printf("couldnt %x find by public vaddr\n", addr);
    } else {
        printf("Found %x by public addr\n", addr);
        return dma_alloc[err].paddr;
    }
    return (void*)-1; //! will crash
}

int sel4_dma_map_new(void **k, bus_dma_segment_t *sg) {
    printf("dmamap map\n");
	*k = (void*) sg->ds_addr;
    printf("alright\n");
    return 0;
}

int sel4_dma_map_load(bus_dmamap_t dmam, void* buf, bus_size_t s) {
    dmam->dm_segs[0].ds_addr = (bus_addr_t) buf;
    dmam->dm_segs[0].ds_len = s;
    return 0;
}

int sel4_dma_map_create_new(bus_dmamap_t *dmap, bus_size_t s, bus_size_t mxs) {
    (*dmap) = ta_alloc(sizeof(**dmap));
	(*dmap)->dm_maxsegsz = mxs;
	(*dmap)->dm_mapsize = s;
	(*dmap)->dm_nsegs = 1;
    return 0;
}

int sel4_dma_malloc_new(size_t size, size_t align, bus_dma_segment_t *sg)
{
    /* Default to alignment on cacheline boundaries */
    // bus_dma_segment_t * new_seg = malloc(sizeof(bus_dma_segment_t));
    sg->ds_addr = (bus_addr_t) sel4_dma_memalign_new(align, size);
    sg->ds_len = size;
    
    return 0;
}

void sel4_dma_initialise_new(ps_dma_man_t *dma_manager)
{
    sel4_dma_manager = dma_manager;

    for (int x = 0; x < MAX_DMA_ALLOCS; x++)
        clear_allocation_new(x);
}

int sel4_dma_free_new(void *vaddr)
{
    // assert(sel4_dma_manager != NULL);

    // Find the previous allocation.
    int alloc_index = find_allocation_index_by_public_vaddr(vaddr);
    if (alloc_index < 0) {
        // ZF_LOGE("Call to free DMA allocation not in bookkeeping");
        return 0; //shuold be an error
    }

    printf("vaddr = %p, alloc_index = %i", vaddr, alloc_index);

    sel4_dma_manager->dma_free_fn(
        sel4_dma_manager->cookie,
        dma_alloc[alloc_index].mapped_vaddr,
        dma_alloc[alloc_index].size);

    // Allocation cleared. Update bookkeeping.
    clear_allocation_new(alloc_index);
    return 0;
}

void* sel4_dma_virt_to_phys_new(void *vaddr)
{
    // assert(sel4_dma_manager != NULL);

    // Find the allocation containing this address.
    int alloc_index = find_allocation_index_by_public_vaddr(vaddr);
    if (alloc_index >= 0)
        return dma_alloc[alloc_index].paddr +
            (vaddr - dma_alloc[alloc_index].public_vaddr);

    printf("ERROR, unable to determine virtual %p\n", vaddr);
    // ZF_LOGE("Unable to determine physical address from virtual %p", vaddr);
    /* This is a fatal error. Not being able to determine an address
        * indicates that we are attempting to communicate with a
        * device via memory that has not been mapped into the physical
        * address space. This implies that additional data needs to be
        * DMA allocated. */
    // assert(false);
}

int sel4_dma_flush_range_new(void *start, void *stop)
{
    return 0;
}