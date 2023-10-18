/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

#include <linux/types.h>

void* sel4_io_map_virt_to_phys(void *vaddr);

void* sel4_io_map_phys_to_virt(void *paddr);

bool sel4_io_map_is_paddr_mapped(void *vaddr);