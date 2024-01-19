/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 * 
 */

#include <linux/kernel.h>

void initialise_and_start_timer(void);

void shutdown_timer(void);

void udelay(unsigned long);

static inline void mdelay(unsigned long msec)
{
	udelay(1000 * msec);
}

static inline void ndelay(unsigned long nsec)
{
	udelay(DIV_ROUND_UP(nsec, 1000));
}
