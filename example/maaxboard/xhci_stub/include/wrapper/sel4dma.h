#include <evbarm/bus_defs.h>
#include <io.h>

// void sel4_dma_initialise_new(ps_dma_man_t *);
int sel4_dma_malloc_new(size_t, size_t, bus_dma_segment_t *);
int sel4_dma_free_new(void *);
int sel4_dma_flush_range_new(void *, void *);
int sel4_dma_map_new(void **, bus_dma_segment_t *);
int sel4_dma_map_create_new(bus_dmamap_t*, bus_size_t s, bus_size_t mxs);
int sel4_dma_map_load(bus_dmamap_t, void*, bus_size_t s);
void*	sel4_dma_dmaaddr(void *);
void*  sel4_dma_virt_to_phys_new(void *);
void sel4_dma_initialise_new(ps_dma_man_t *);