/* 
 * Copyright 2022, Capgemini Engineering 
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

/* Routines to perform initialisation and shutdown of the U-Boot wrapper.
 * The initialise routine performs the actions that would normally be
 * performed by U-Boot when it is started.
 */


int initialise_uboot_wrapper(char* fdt_blob);

void shutdown_uboot_wrapper(void);

// /* Routines for start up and shutdown of DMA management */

// void sel4_dma_initialise(ps_dma_man_t *dma_manager);

// void sel4_dma_shutdown(void);

// /* Routines for start up and shutdown of IO mapping management */

// void sel4_io_map_initialise(ps_io_mapper_t *io_mapper);

// void sel4_io_map_shutdown(void);

// void sel4_io_map_do_unmap(void *vaddr);

// void* sel4_io_map_do_map(uintptr_t paddr, size_t size);