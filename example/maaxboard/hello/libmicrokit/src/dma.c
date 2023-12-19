/* This work is Crown Copyright NCSC, 2023. */
/*
 * Copyright 2017, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
/* Author: alex.kroh@nicta.com.au */

#include <dma/dma.h>
#include <printf.h>
// #include <wrapper.h>
#include <tinyalloc.h>
// #include <sys/kmem.h>
#include <linux/dma-direction.h>

uintptr_t phys_base;
uintptr_t virt_base;
uintptr_t dma_limit;
uintptr_t allocated_dma;

/* #define DMA_DEBUG */

#ifdef DMA_DEBUG
#define dma_print(...) printf(__VA_ARGS__)
#else
#define dma_print(...) 0
#endif

void sel4_dma_init(uintptr_t pbase, uintptr_t vbase, uintptr_t limit) {
    phys_base = pbase;
    allocated_dma = vbase;
    virt_base = vbase;
    dma_limit = limit;
    dma_print("init phys_base: %p, vbase: %p\n", phys_base, virt_base);
}

void* sel4_dma_malloc(size_t size) {
    if (allocated_dma + size >= dma_limit) {
        dma_print("DMA_ERROR: out of memory\n");
        return 0;
    }
    uintptr_t start_addr = allocated_dma;
    allocated_dma += size;
    dma_print("Alloced at %p size %p\n", start_addr, size);
    return start_addr;
}

void* sel4_dma_clear(){
    allocated_dma = virt_base;
}

uintptr_t* getPhys(void* virt) {
    int offset = (uint64_t)virt - (int)virt_base;
    dma_print("offset = %d\n", offset);
    dma_print("getting phys of %p: %p\n", virt, phys_base+offset);
    return (uintptr_t*)(phys_base+offset);
}

uintptr_t* getVirt(void* paddr) {
    uintptr_t *offset = paddr - phys_base;
    dma_print("getting virt of %p: %p\n", paddr, virt_base+offset);
    return (virt_base + offset);
}

bool sel4_dma_is_mapped(void *vaddr){
    return true;
}

void *sel4_dma_map_single(void* public_vaddr, size_t size, enum dma_data_direction dir){
    return 0;
}

void sel4_dma_unmap_single(void* paddr){
    return 0;
}

void flush_dcache_range(unsigned long start, unsigned long stop){
    return 0;
}

void invalidate_dcache_range(unsigned long start, unsigned long end){
    return 0;
}

void sel4_dma_free(void *vaddr){
    return 0;
}
