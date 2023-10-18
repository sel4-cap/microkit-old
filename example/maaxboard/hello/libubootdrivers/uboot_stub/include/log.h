/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

/* Minimal stub (mostly replaced by uboot_print.h */

#pragma once

/**
 * enum log_level_t - Log levels supported, ranging from most to least important
 */
enum log_level_t {
	/** @LOGL_EMERG: U-Boot is unstable */
	LOGL_EMERG = 0,
	/** @LOGL_ALERT: Action must be taken immediately */
	LOGL_ALERT,
	/** @LOGL_CRIT: Critical conditions */
	LOGL_CRIT,
	/** @LOGL_ERR: Error that prevents something from working */
	LOGL_ERR,
	/** @LOGL_WARNING: Warning may prevent optimal operation */
	LOGL_WARNING,
	/** @LOGL_NOTICE: Normal but significant condition, printf() */
	LOGL_NOTICE,
	/** @LOGL_INFO: General information message */
	LOGL_INFO,
	/** @LOGL_DEBUG: Basic debug-level message */
	LOGL_DEBUG,
	/** @LOGL_DEBUG_CONTENT: Debug message showing full message content */
	LOGL_DEBUG_CONTENT,
	/** @LOGL_DEBUG_IO: Debug message showing hardware I/O access */
	LOGL_DEBUG_IO,

	/** @LOGL_COUNT: Total number of valid log levels */
	LOGL_COUNT,
	/** @LOGL_NONE: Used to indicate that there is no valid log level */
	LOGL_NONE,

	/** @LOGL_LEVEL_MASK: Mask for valid log levels */
	LOGL_LEVEL_MASK = 0xf,
	/** @LOGL_FORCE_DEBUG: Mask to force output due to LOG_DEBUG */
	LOGL_FORCE_DEBUG = 0x10,

	/** @LOGL_FIRST: The first, most-important log level */
	LOGL_FIRST = LOGL_EMERG,
	/** @LOGL_MAX: The last, least-important log level */
	LOGL_MAX = LOGL_DEBUG_IO,
	/** @LOGL_CONT: Use same log level as in previous call */
	LOGL_CONT = -1,
};