/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

/* Dummy timer. Raises an assert if actively used */

void initialise_and_start_timer(void) {
}

void shutdown_timer(void) {
}

uint64_t get_ticks(void) {
    assert(false);
}

unsigned long timer_get_us(void) {
    assert(false);
}

unsigned long timer_get_ms(void) {
    assert(false);
}

unsigned long get_timer(unsigned long base) {
    assert(false);
}