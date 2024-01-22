/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

/* Provide an seL4 compliant implemention of panic as used by U-Boot */

#include <hang.h>

void hang(void)
{
	assert(false);
}

void panic(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	printf(fmt, args);
	va_end(args);
	hang();
}