/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

#ifndef __LINKER_LISTS_H__
#define __LINKER_LISTS_H__

/* This is a replacement version of the linker_lists header file provided
 * U-Boot. Instead of mapping on to entries in a special linker section we
 * instead just map on to entries in the driver_data instantiation of the
 * driver_data_t structure.
 */

#define llsym(_type, _name, _list) 	((_type *)&_u_boot_##_list##__##_name)

#define ll_entry_declare(_type, _name, _list)	_type _u_boot_##_list##__##_name

#define ll_entry_start(_type, _list)	(_type *)driver_data_start._list##_start

#define ll_entry_end(_type, _list)	(_type *)driver_data_end._list##_start

#define ll_entry_count(_type, _list)	_u_boot_##_list##_count

#define ll_entry_get(_type, _name, _list)											\
	({																				\
		extern _type _u_boot_##_list##__##_name;									\
		_type *_ll_result =															\
			&_u_boot_##_list##__##_name;											\
		_ll_result;																	\
	})

#define ll_entry_ref(_type, _name, _list)	((_type *)&_u_boot_##_list##__##_name)

#endif	/* __LINKER_LISTS_H__ */