/* This work is Crown Copyright NCSC, 2023. */
/*
 * Copyright 2017, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
/* Author: alex.kroh@nicta.com.au */

#define __thread
#include <sel4/sel4.h>
// #include <wrapper.h>
// #include <sys/kmem.h>
#include <linux/dma-direction.h>
#include <stdbool.h>
#include <stdio.h>
#include <sel4/sel4.h>

uintptr_t phys_base;
uintptr_t virt_base;
uintptr_t dma_limit;
uintptr_t allocated_dma;

uintptr_t dma_base;
uintptr_t dma_cp_paddr;
uintptr_t dma_cp_vaddr = 0x54000000;

typedef struct dma_block {
    uintptr_t start_addr;
    size_t size;
    struct dma_block *next;
} dma_block_t;

dma_block_t *dma_head = NULL;

// Define CACHE_LINE_SIZE based on your ARM CPU architecture
#define CACHE_LINE_SIZE 64  // Adjust this value based on your specific ARM CPU

#define DMA_DEBUG 

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
    printf("sel4_dma_init\n");
    printf("allocated_dma %x\n", allocated_dma);
    dma_print("init phys_base: %p, vbase: %p\n", phys_base, virt_base);
}



void* sel4_dma_malloc(size_t size) {

    printf("sel4 dma malloc\n");
    printf("allocated_dma %x\n", allocated_dma);
    
    if (!size) {
        return NULL;
    }

    // Align size to a multiple of the cache line size for efficiency
    size = (size + CACHE_LINE_SIZE - 1) & ~(CACHE_LINE_SIZE - 1);

    uintptr_t new_alloc = allocated_dma + size;
    if (new_alloc >= dma_limit) {
        dma_print("DMA_ERROR: out of memory\n");
        return NULL;
    }

    // Create a new block and add it to the list
    dma_block_t *block = malloc(sizeof(dma_block_t));
    if (!block) {
        return NULL;
    }
    block->start_addr = allocated_dma;
    block->size = size;
    block->next = dma_head;
    dma_head = block;

    printf("Malloc: DMA head is %x\n", dma_head);

    allocated_dma = new_alloc;
    dma_print("Allocated at %p size %p\n", block->start_addr, size);
    return (void *)block->start_addr;
}

void sel4_dma_free(void *ptr) {

    printf("sel4_dma_free\n");
    printf("allocated_dma %x\n", allocated_dma);

    printf("Pointer being freed %x\n", ptr);

    if(ptr < dma_cp_vaddr || ptr > dma_limit){
        dma_print("Trying to free non dma memory\n");
        return 0;
    }

    dma_block_t *prev = NULL;
    dma_block_t *current = dma_head;

    while (current) {
        if ((uintptr_t)ptr == current->start_addr) {
            if (prev) {
                prev->next = current->next;
            } else {
                dma_head = current->next;
            }

            dma_print("Freed DMA memory at %p\n", ptr);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    dma_print("DMA_ERROR: Invalid free request\n");
}

void* sel4_dma_memalign(size_t alignment, size_t size) {

    static bool initialised = false;

    if(!initialised){
        sel4_dma_init(dma_cp_paddr, dma_cp_vaddr, dma_cp_vaddr + 0x2000000);
        initialised = true;
    }
       
    
    printf("sel4 dma memalign\n");
    printf("allocated_dma %x\n", allocated_dma);


    if (!size || alignment == 0) {
        printf("Failed here\n");
        return NULL;
    }

    // Ensure the alignment is at least as large as a pointer
    alignment = (alignment < sizeof(void*)) ? sizeof(void*) : alignment;

    // Align size to a multiple of the cache line size for efficiency
    size = (size + CACHE_LINE_SIZE - 1) & ~(CACHE_LINE_SIZE - 1);

    // Ensure alignment is a power of two
    if ((alignment & (alignment - 1)) != 0) {
        dma_print("DMA_ERROR: Alignment is not a power of two\n");
        return NULL;
    }

    // Calculate the worst case allocation address by adding alignment - 1
    uintptr_t worst_case_addr = allocated_dma + alignment - 1;
    printf("worst_case_addr %x\n", worst_case_addr);
    // Align the address down to the required alignment
    uintptr_t aligned_addr = worst_case_addr & ~(alignment - 1);

    // Check if aligned address goes beyond the DMA limit
    printf("aligned addr %x\n", aligned_addr);
    if (aligned_addr + size > dma_limit) {
        printf("aligned_addr + size %x\n", aligned_addr + size);
        printf("dma limit %x\n", dma_limit);
        dma_print("DMA_ERROR: Aligned allocation exceeds memory limit\n");
        return NULL;
    }

    // Create a new block and add it to the list
    dma_block_t *block = malloc(sizeof(dma_block_t));
    if (!block) {
        return NULL;
    }
    block->start_addr = aligned_addr;
    block->size = size;
    block->next = dma_head;
    dma_head = block;

    printf("Memalign: DMA head is %x\n", dma_head);

    allocated_dma = aligned_addr + size;
    dma_print("Aligned allocation at %p size %p\n", block->start_addr, size);
    return (void *)block->start_addr;
}

uintptr_t* getPhys(void* virt) {
    printf("getPhys\n");
    printf("virt_base %x\n", virt_base);
    int offset = (uint64_t)virt - (int)virt_base;
    dma_print("offset = %d\n", offset);
    dma_print("getting phys of %p: %p\n", virt, phys_base+offset);
    return (uintptr_t*)(virt);
}

uintptr_t* getVirt(void* paddr) {
    printf("getVirt\n");
    printf("virt_base %x\n", phys_base);
    uintptr_t *offset = paddr - phys_base;
    dma_print("getting virt of %p: %p\n", paddr, virt_base+offset);
    return (paddr);
}

void sel4_dma_flush_range(uintptr_t start, uintptr_t stop) {
    printf("sel4_dma_flush_range\n");
    printf("Start %x\n", start);
    printf("Stop %x\n", stop);
    uintptr_t end = stop;

    // Ensure that the range is within the allocated DMA memory
    if (start < virt_base || end > allocated_dma) {
        dma_print("Error: Range to flush is outside allocated DMA memory\n");
        return;
    }

    // Align start address to cache line boundary
    start &= ~(CACHE_LINE_SIZE - 1);

    // Flush each cache line in the range
    for (uintptr_t addr = start; addr < end; addr += CACHE_LINE_SIZE) {
        printf("here 1\n");
        asm volatile("dc civac, %0" : : "r" (addr) : "memory");
    }

    // Ensure completion of cache flush
    __asm__ volatile("dsb sy");
    printf("here 2\n");

    dma_print("Cache flush completed for range: %p - %p\n", start, end);
}

void sel4_dma_invalidate_range(uintptr_t start, uintptr_t stop) {
    printf("sel4_dma_invalidate_range\n");
    uintptr_t end = stop;

    // Ensure that the range is within the allocated DMA memory
    if (start < virt_base || end > allocated_dma) {
        dma_print("Error: Range to invalidate is outside allocated DMA memory\n");
        return;
    }

    // Align start address to cache line boundary
    start &= ~(CACHE_LINE_SIZE - 1);

    // Invalidate each cache line in the range
    for (uintptr_t addr = start; addr < end; addr += CACHE_LINE_SIZE) {
        asm volatile("dc ivac, %0" : : "r" (addr) : "memory");
    }

    // Ensure completion of cache invalidation
    __asm__ volatile("dsb sy");

    dma_print("Cache invalidate completed for range: %p - %p\n", start, end);
}

void sel4_dma_clear_all() {
    printf("sel4_dma_clear_all\n");
    dma_block_t *current = dma_head;
    while (current != NULL) {
        printf("Dma pointer currently at %x\n", current);
        dma_block_t *temp = current;
        current = current->next;
        free(temp);  // Free the memory used by the dma_block_t node
    }

    // Reset the head of the list and the allocated_dma pointer
    dma_head = NULL;
    allocated_dma = virt_base;


    dma_print("All DMA memory cleared\n");
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

void flush_dcache_range(unsigned long start, unsigned long stop)
{
	// sel4_dma_flush_range((void*) start, (void *) stop);
    seL4_ARM_VSpace_CleanInvalidate_Data(3, start, stop);
}

void invalidate_dcache_range(unsigned long start, unsigned long end) 
{
    // sel4_dma_invalidate_range((void*) start, (void*) end);
    seL4_ARM_VSpace_Invalidate_Data(3, start, end);
}

