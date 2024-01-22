/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

#pragma once

/*
 * This file contains the base U-Boot configuration macros that must be in
 * place for the driver library and the base set of includes that are required
 * to cleanly compile the U-Boot source files.
 */


/* Enable seL4 specific code modifications to the U-Boot source files */
#define CONFIG_SEL4

/* Base defines expected by U-Boot */
#define __KERNEL__
#define __UBOOT__

/* Enable use of U-Boot's Driver Model (DM) driver framework */
#define CONFIG_DM                       1
#define CONFIG_DM_DEVICE_REMOVE			1

/* Enable use of the 'live' Open Firmware (OF) device tree */
#define CONFIG_OF_LIBFDT				1
#define CONFIG_OF_LIVE   				1
#define CONFIG_OF_REAL          		1
#define CONFIG_OF_CONTROL          		1

/* Enable use of the U-Boot command line interface */
#define CONFIG_CMDLINE                  1
#define CONFIG_SYS_MAXARGS              64 /* Max number of args in a command */
#define CONFIG_SYS_CBSIZE               256 /* Size of the console (input) buffer */
#define CONFIG_SYS_PBSIZE               256 /* Size of the print (ouput) buffer */
#define CONFIG_SYS_PROMPT               "" /* Command prompt */

/* Environment variable settings */
#define CONFIG_ENV_IS_NOWHERE           1
#define CONFIG_ENV_SIZE                 0x2000 /* 8K of env variable storage */

/* Settings related to standard input / output files */
#define CONFIG_SYS_DEVICE_NULLDEV       1 /* Define null stdio devices */
#define MAX_FILES   	                3 /* stdin, stdout and stderr */

/* Base settings for drivers */
#define CONFIG_PHY                      1 /* Allow use of PHY drivers */
#define CONFIG_DEVRES           		1 /* Allow device resource management */
#define CONFIG_BLK                      1 /* Allow use of block device drivers */

/* Disable mutex support. Library is not intended to be thread-safe */
#define mutex_init(...)
#define mutex_lock(...)
#define mutex_unlock(...)

/* Disable symbols not required / supported */
#define EXPORT_SYMBOL(...)
#define __bitwise 		/* __attribute__((bitwise)) */
#define __force 		/* __attribute__((force)) */
#define __iomem			/* __attribute__((iomem)) */

/* Assorted macros needed to keep U-Boot source code happy */
#define CONFIG_SYS_RX_ETH_BUFFER    4
#define CONFIG_LINKER_LIST_ALIGN    0
#define CONFIG_ERR_PTR_OFFSET   	0
#define CONFIG_NR_DRAM_BANKS		0 /* Not used */
#define CONFIG_LMB_MEMORY_REGIONS   0 /* Not used */
#define CONFIG_LMB_RESERVED_REGIONS 0 /* Not used */
#define CONFIG_SYS_HZ               1000 /* System, e.g. console, update rate */
#define CONFIG_SYS_LOAD_ADDR        0
#define _DEBUG			            false /* Don't force debug logging */
#define UNREACHABLE()               __builtin_unreachable()

/* Provide a definition of off_t and prevent muslc from defining it.
 * This prevents a name-space clash between muslc and the U-Boot types */
#define __DEFINED_off_t
typedef long off_t;

/* Helper macros to wrap U-Boot 'print' routines on to seL4 equivalents */
#include <uboot_print.h>


/* Undefine the macros defined by seL4 / muslc to allow U-Boot code to redefine */
#undef ALIGN
#undef stdin
#undef stdout
#undef stderr

/* Provide default indexes for the stdin / stdout / stderr 'files' */
#define stdin_uboot   0
#define stdout_uboot  1
#define stderr_uboot  2

/* Include headers expected by all U-Boot source code */


#include <linux/kernel.h>
#include <linux/kconfig.h>
#include <sel4_dma.h>
// #include <sel4_io_map.h>
#include <common.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <vsprintf.h>
#include <assert.h>
#include <plat_driver_data.h>
#include <driver_data_limits.h>
#include <linux/libfdt_env.h>
#include <linux/libfdt.h>

/* Include headers for microkit*/
#include <microkit.h>

#undef __KERNEL_STRICT_NAMES


/* Replace uses of U-Boot's lldiv function with the equivalent from picolibc */
#define __ldiv_t_defined
#define lldiv(A, B)     lldiv(A, B).quot

// Renames to build with picolibc
#define stderr stderr_uboot
#define stdin stdin_uboot
#define stdout stdout_uboot
#define log log_uboot
#undef putc
#define putc putc_uboot
#undef getc
#define getc getc_uboot
#define putc_uboot microkit_dbg_putc
// #define malloc(size) ta_alloc(size)
// #define free ta_free