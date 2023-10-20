// #include <io.h>
// #include <bus_defs.h>
#include <stdint.h>
#include <stddef.h>

struct bus_dma_segment {
	/*
	 * PUBLIC MEMBERS: these are used by machine-independent code.
	 */
	uintptr_t	ds_addr;	/* DMA address */
	size_t	ds_len;		/* length of transfer */
};
typedef struct bus_dma_segment	bus_dma_segment_t;

int sel4_dma_alloc(size_t, bus_dma_segment_t *);
void sel4_dma_init(uintptr_t, uintptr_t, uintptr_t);
uintptr_t* getPhys(void*);
uintptr_t* getVirt(void*);
