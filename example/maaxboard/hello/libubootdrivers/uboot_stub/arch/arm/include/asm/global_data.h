/* SPDX-License-Identifier: GPL-2.0+
 *
 * (C) Copyright 2002-2010
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 * 
 * (C) Copyright 2022, Capgemini Engineering
 * 
 */

/* Minimal stub. Minimal architecture specific global data required */

#ifndef	__ASM_GBL_DATA_H
#define __ASM_GBL_DATA_H

#ifndef __ASSEMBLY__

#include <config.h>

#include <asm/types.h>
#include <linux/types.h>

/* Architecture-specific global data */
struct arch_global_data {
#if defined(CONFIG_FSL_ESDHC) || defined(CONFIG_FSL_ESDHC_IMX)
	u32 sdhc_clk;
#endif

#if defined(CONFIG_FSL_ESDHC)
	u32 sdhc_per_clk;
#endif

};

#include <asm-generic/global_data.h>

#define DECLARE_GLOBAL_DATA_PTR   extern gd_t *gd

#endif /* __ASSEMBLY__ */

#endif /* __ASM_GBL_DATA_H */