/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: GPL-2.0
 *
 */

#ifndef _LINUX_DMA_MAPPING_H
#define _LINUX_DMA_MAPPING_H

#include <linux/dma-direction.h>
#include <linux/types.h>
#include <asm/cache.h>
#include <sel4_dma.h>

static inline void *dma_alloc_coherent(size_t len, unsigned long *handle)
{
	return sel4_dma_memalign(ARCH_DMA_MINALIGN, ROUND(len, ARCH_DMA_MINALIGN));
}

static inline void dma_free_coherent(void *addr)
{
	sel4_dma_free(addr);
}

static inline bool dma_mapping_error(struct udevice *dev, dma_addr_t addr)
{
	return !sel4_dma_is_mapped((void *) addr);
}

static inline dma_addr_t dma_map_single(void *vaddr, size_t len,
					enum dma_data_direction dir)
{
	return (dma_addr_t) sel4_dma_map_single(vaddr, len, dir);
}

static inline void dma_unmap_single(dma_addr_t addr, size_t len,
				    enum dma_data_direction dir)
{
	sel4_dma_unmap_single((void*) addr);
}

#endif