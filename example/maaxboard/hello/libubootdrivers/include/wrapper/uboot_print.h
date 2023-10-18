/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

/* Wrappers around U-Boot print string routines */

#include <utils/zf_log.h>
#include <stdio.h>
#include <log.h>

/* Define U-Boot debug_xxx macros */
#define debug(...)          ZF_LOGD(__VA_ARGS__)
#define debug_cond(A, ...)  ZF_LOGD(__VA_ARGS__)

/* Define U-Boot log_xxx macros */
#define log(_cat, _level, ...) ({ 							\
	if      (_level <= LOGL_EMERG)   ZF_LOGF(__VA_ARGS__);	\
	else if (_level <= LOGL_ERR)     ZF_LOGE(__VA_ARGS__);	\
	else if (_level <= LOGL_WARNING) ZF_LOGW(__VA_ARGS__);	\
	else if (_level <= LOGL_INFO)    ZF_LOGI(__VA_ARGS__);	\
	else if (_level <= LOGL_DEBUG)   ZF_LOGD(__VA_ARGS__);	\
	else							 ZF_LOGV(__VA_ARGS__);	\
	})

#define log_emer(_fmt...)		log(0, LOGL_EMERG, ##_fmt)
#define log_alert(_fmt...)		log(0, LOGL_ALERT, ##_fmt)
#define log_crit(_fmt...)		log(0, LOGL_CRIT, ##_fmt)
#define log_err(_fmt...)		log(0, LOGL_ERR, ##_fmt)
#define log_warning(_fmt...)	log(0, LOGL_WARNING, ##_fmt)
#define log_notice(_fmt...)		log(0, LOGL_NOTICE, ##_fmt)
#define log_info(_fmt...)		log(0, LOGL_INFO, ##_fmt)
#define log_debug(_fmt...)		log(0, LOGL_DEBUG, ##_fmt)
#define log_content(_fmt...)	log(0, LOGL_DEBUG_CONTENT, ##_fmt)
#define log_io(_fmt...)			log(0, LOGL_DEBUG_IO, ##_fmt)
#define log_cont(_fmt...)		log(0, LOGL_CONT, ##_fmt)

#define log_ret(_ret) ({ \
	int __ret = (_ret); \
	if (__ret < 0) \
		ZF_LOGE("returning err=%d\n", __ret); \
	__ret; \
	})

#define log_msg_ret(_msg, _ret) ({ \
	int __ret = (_ret); \
	if (__ret < 0) \
		ZF_LOGE("%s: returning err=%d\n", _msg, __ret); \
	__ret; \
	})

/* Define U-Boot printk macros */
#define no_printk(...)
#define printk(...)         	printf(__VA_ARGS__)
#define printk_once(fmt, ...)	printk(fmt, ##__VA_ARGS__)
#define pr_emerg(fmt, ...)		log_emerg(fmt, ##__VA_ARGS__)
#define pr_alert(fmt, ...)		log_alert(fmt, ##__VA_ARGS__)
#define pr_crit(fmt, ...)		log_crit(fmt, ##__VA_ARGS__)
#define pr_err(fmt, ...)		log_err(fmt, ##__VA_ARGS__)
#define pr_warn(fmt, ...)		log_warning(fmt, ##__VA_ARGS__)
#define pr_notice(fmt, ...)		log_notice(fmt, ##__VA_ARGS__)
#define pr_info(fmt, ...)		log_info(fmt, ##__VA_ARGS__)
#define pr_debug(fmt, ...)		log_debug(fmt, ##__VA_ARGS__)
#define pr_devel(fmt, ...)		log_debug(fmt, ##__VA_ARGS__)
#define pr_cont(fmt, ...)		log_cont(fmt, ##__VA_ARGS__)

/* Define miscellaneous logging routines */
#define putc(CHAR)          printf("%c", CHAR)
#define puts(...)           printf(__VA_ARGS__)
#define fprintf(FILE, ...)	printf(__VA_ARGS__)

/* Define non spl logging routines */
#define warn_non_spl(fmt, ...)	log_warning(fmt, ##__VA_ARGS__)

#define assert_noisy(_x) \
	({ bool _val = (_x); \
	if (!_val) \
		panic("assert_noisy triggered"); \
	_val; \
	})
