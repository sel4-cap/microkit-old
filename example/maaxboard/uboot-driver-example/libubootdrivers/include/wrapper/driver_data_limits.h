/* 
 * Copyright 2022, Capgemini Engineering
 * 
 * SPDX-License-Identifier: GPL-2.0+ 
 *
 */

#ifndef	__DRIVER_DATA_LIMITS_H
#define __DRIVER_DATA_LIMITS_H

struct driver_data_pointer_t {
    void *driver_start;
    void *uclass_driver_start;
    void *usb_driver_entry_start;
    void *cmd_start;
    void *part_driver_start;
    void *env_driver_start;
    void *env_clbk_start;
    void *driver_info_start;
    void *udevice_start;
};

extern const struct driver_data_pointer_t driver_data_start;
extern const struct driver_data_pointer_t driver_data_end;

#endif /* __DRIVER_DATA_LIMITS_H */