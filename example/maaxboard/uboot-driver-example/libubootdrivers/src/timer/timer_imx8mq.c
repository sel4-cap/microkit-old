/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

/* This timer uses the System Counter (SYS_CTR) provided by the iMX8MQ SoC
 * to implement the timing functions expected by the U-Boot codebase */

#include <common.h>
#include <asm/arch-imx8m/imx-regs.h>
#include <asm/io.h>
#include <hang.h>
#include <sel4/sel4.h>

// #define TIMER_DEBUG
#ifdef TIMER_DEBUG
#define timer_print(...) printf(__VA_ARGS__)
#else
#define timer_print(...) 0
#endif

#define hang() 0 //noop

struct cntl_reg {
	uint32_t cntcr;
	uint32_t cntsr;
	uint32_t cntcv0;
	uint32_t cntcv1;
    uint32_t rsvd0[4];
    uint32_t cntfid0;
    uint32_t cntfid1;
    uint32_t cntfid2;
};

#define CNTCR_EN    0x0b
#define CNTCR_FCR0  0x1000b

static struct cntl_reg *ctrl_reg = (struct cntl_reg *)SYSCNT_CTRL_BASE_ADDR;

uint64_t tick_frequency = 0;
uintptr_t timer_base;
uintptr_t tmr_base;



void initialise_and_start_timer(void)
{
    /* Read tick frequency associated with the base counter */
    tmr_base = timer_base;
    tick_frequency = readl(tmr_base + 0x020);
    printf("After tick frequency \n");

    if (tick_frequency < 1000000) {
        log_err("Fatal: System counter tick frequency is too low for accurate timing\n");
        hang();
    }

    printf("before write\n");
    /* Set the enable bitand select the base frequency */
    writel(CNTCR_EN | CNTCR_FCR0, tmr_base);
    printf("after write\n");
}

void shutdown_timer(void)
{
    /* Nothing to do here. It would be unsafe to stop the timer as other
     * instances of the library may still be using it */
}

/* Provide implementations of the various timer functions used by U-Boot */
uint64_t get_ticks(void) {

    if (tick_frequency == 0) {
        printf("Fatal: Attempt to read from uninitialised timer\n");
        hang();
    }
    uint32_t initial_high = readl(tmr_base + 0x00); //cntcv1
    uint32_t low = readl(tmr_base + 0x08); //cntcv0
    uint32_t high = readl(tmr_base + 0x00); //cntcv1
    if (high != initial_high) {
        /* get low again if high has ticked over. */
        low = readl(tmr_base + 0x08); //cntcv0
        printf("Tick over low: %x\n", low);
    }

    return (((uint64_t)high << 32) | low);
}

unsigned long timer_get_us(void) {
    /* To improve accuracy we shift ticks left by 7 bits. Note that
    * the counter value is only a 57 bit value so this is safe.
    * When calculating the resulting time this shift is accounted for.
    */

    uint64_t ticks_per_us = ((uint64_t)tick_frequency << 7) / 1000000;

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

void mdelay(int delay) {
    timer_print("delay is %i\n", delay);
    timer_print("TIMER START\n");
    unsigned long timer_count_init = get_ticks();
	timer_print("Start count: %ld\n", timer_count_init);
    unsigned long delay_ticks = delay*(tick_frequency/1000);
    timer_print("Delay ticks: %ld\n", delay_ticks);
	while (get_ticks() < timer_count_init + delay_ticks) {
        seL4_Yield();
	}
	timer_print("Finish count: %ld\n", get_ticks());
    timer_print("Target end was: %ld\n", timer_count_init + delay_ticks);
    timer_print("TIMER END\n");
}
