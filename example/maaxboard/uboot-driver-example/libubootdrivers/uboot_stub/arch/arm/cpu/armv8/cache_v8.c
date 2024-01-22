/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

/* MMU always enabled in seL4 */
int mmu_status(void) {
    return 1;
}