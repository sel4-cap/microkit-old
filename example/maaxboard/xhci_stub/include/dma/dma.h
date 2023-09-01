
#pragma once

#include <io.h>
#include <machine/bus_defs.h>
#include <stdint.h>
#include <stddef.h>

int sel4_dma_map(void **, bus_dma_segment_t *);
int sel4_dma_map_load(bus_dmamap_t, void*, bus_size_t);
int sel4_dma_map_create(bus_dmamap_t *, bus_size_t, bus_size_t);
int sel4_dma_alloc(size_t, bus_dma_segment_t *);
void sel4_dma_init(uintptr_t, uintptr_t, uintptr_t);
int sel4_dma_alloc(size_t, bus_dma_segment_t*);
uintptr_t* getPhys(void*);
uintptr_t* getVirt(void*);
