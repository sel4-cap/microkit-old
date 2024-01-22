// #include <io.h>
// #include <bus_defs.h>
#include <stdint.h>
#include <stddef.h>

// #define sel4_dma_memalign(a,b) memalign(a,b)
#define sel4_dma_virt_to_phys(A) getPhys(A)
#define sel4_dma_phys_to_virt(A) getVirt(A)

void* sel4_dma_malloc(size_t);
void sel4_dma_init(uintptr_t, uintptr_t, uintptr_t);
void* sel4_dma_memalign(size_t, size_t);
void sel4_dma_clear_all(void);
uintptr_t* getPhys(void*);
uintptr_t* getVirt(void*);
void sel4_dma_free(void*); 
bool sel4_dma_is_mapped(void*);
int sel4_dma_map_single(void* public_vaddr, size_t size, enum dma_data_direction dir);
int sel4_dma_unmap_single(void *paddr);
