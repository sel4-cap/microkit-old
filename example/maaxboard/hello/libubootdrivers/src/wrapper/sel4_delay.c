/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

#include <platsupport/delay.h>

void udelay(unsigned long usec)
{
    ps_udelay(usec);
}

void __udelay(unsigned long usec)
{
    ps_udelay(usec);
}
