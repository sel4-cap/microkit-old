/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

#include <asm/mach-imx/module_fuse.h>

#ifdef CONFIG_IMX8MQ
#define is_mx6()        0
#define is_mx6sx()      0
#define is_mx6ul()      0
#define is_mx6ull()     0
#define is_mx7()        0
#define is_imx8()       1
#define is_imx8m()      1
#define is_imx8mp()     0
#define is_imx8mq()     1
#define is_imx8ulp()    0
#endif

void imx_get_mac_from_fuse(int dev_id, unsigned char *mac);
