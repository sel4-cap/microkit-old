/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

/* This timer uses the System Counter (SYS_CTR) provided by the iMX8MQ SoC
 * to implement the timing functions expected by the U-Boot codebase */

#include <common.h>
#include <asm/arch/imx-regs.h>
#include <asm/io.h>
#include <hang.h>

struct cntl_reg {
	u32	cntcr;
	u32	cntsr;
	u32	cntcv0;
	u32	cntcv1;
    u32 rsvd0[4];
    u32 cntfid0;
    u32 cntfid1;
    u32 cntfid2;
};

#define CNTCR_EN    BIT(0)
#define CNTCR_FCR0  BIT(8)


static struct cntl_reg *ctrl_reg = (struct cntl_reg *)SYSCNT_CTRL_BASE_ADDR;

static u64 tick_frequency = 0;


void initialise_and_start_timer(void)
{
    /* Read tick frequency associated with the base counter */
    tick_frequency = readl(&ctrl_reg->cntfid0);

    if (tick_frequency < 1000000) {
        log_err("Fatal: System counter tick frequency is too low for accurate timing\n");
        hang();
    }

    /* Set the enable bitand select the base frequency */
    writel(CNTCR_EN | CNTCR_FCR0, &ctrl_reg->cntcr);
}

void shutdown_timer(void)
{
    /* Nothing to do here. It would be unsafe to stop the timer as other
     * instances of the library may still be using it */
}

/* Provide implementations of the various timer functions used by U-Boot */

uint64_t get_ticks(void) {

    if (tick_frequency == 0) {
        log_err("Fatal: Attempt to read from uninitialised timer\n");
        hang();
    }

    u32 initial_high = readl(&ctrl_reg->cntcv1);
    u32 low = readl(&ctrl_reg->cntcv0);
    u32 high = readl(&ctrl_reg->cntcv1);
    if (high != initial_high) {
        /* get low again if high has ticked over. */
        low = readl(&ctrl_reg->cntcv0);
    }

    return (((u64)high << 32) | low);
}

unsigned long timer_get_us(void) {
    /* To improve accuracy we shift ticks left by 7 bits. Note that
    * the counter value is only a 57 bit value so this is safe.
    * When calculating the resulting time this shift is accounted for.
    */

    u64 ticks_per_us = ((u64)tick_frequency << 7) / 1000000;

    return (get_ticks() << 7) / ticks_per_us;
}

unsigned long timer_get_ms(void) {
    return timer_get_us() / 1000;
}

unsigned long get_timer(unsigned long base) {
    unsigned long time = timer_get_ms();
    if (time <= base)
        return 0;
    else
        return time - base;
}