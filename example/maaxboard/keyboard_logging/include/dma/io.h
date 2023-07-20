#pragma once 
#include <stddef.h>
#include <stdint.h>
#include <assert.h>

typedef enum ps_mem_flags {
    PS_MEM_NORMAL, /* No hints, consider 'normal' memory */
    PS_MEM_HR,     /* Host typically reads */
    PS_MEM_HW      /* Host typically writes */
} ps_mem_flags_t;

typedef enum dma_cache_op {
    DMA_CACHE_OP_CLEAN,
    DMA_CACHE_OP_INVALIDATE,
    DMA_CACHE_OP_CLEAN_INVALIDATE
} dma_cache_op_t;

typedef void *(*ps_dma_alloc_fn_t)(
    void *cookie,
    size_t size,
    int align,
    int cached,
    ps_mem_flags_t flags);

typedef void (*ps_dma_free_fn_t)(
    void *cookie,
    void *addr,
    size_t size);

typedef uintptr_t (*ps_dma_pin_fn_t)(
    void *cookie,
    void *addr,
    size_t size);

typedef void (*ps_dma_unpin_fn_t)(
    void *cookie,
    void *addr,
    size_t size);

typedef void (*ps_dma_cache_op_fn_t)(
    void *cookie,
    void *addr,
    size_t size,
    dma_cache_op_t op);

typedef struct ps_dma_man {
    void *cookie;
    ps_dma_alloc_fn_t dma_alloc_fn;
    ps_dma_free_fn_t dma_free_fn;
    ps_dma_pin_fn_t dma_pin_fn;
    ps_dma_unpin_fn_t dma_unpin_fn;
    ps_dma_cache_op_fn_t dma_cache_op_fn;
} ps_dma_man_t;