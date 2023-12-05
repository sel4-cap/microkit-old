#
# Copyright 2021, Breakaway Consulting Pty. Ltd.
#
# SPDX-License-Identifier: BSD-2-Clause
#
ifeq ($(strip $(BUILD_DIR)),)
$(error BUILD_DIR must be specified)
endif

ifeq ($(strip $(MICROKIT_SDK)),)
$(error MICROKIT_SDK must be specified)
endif
 
ifeq ($(strip $(MICROKIT_BOARD)),)
$(error MICROKIT_BOARD must be specified)
endif

ifeq ($(strip $(MICROKIT_CONFIG)),)
$(error MICROKIT_CONFIG must be specified)
endif

TOOLCHAIN := aarch64-none-elf

CPU := cortex-a53

CC := $(TOOLCHAIN)-gcc
LD := $(TOOLCHAIN)-ld
AS := $(TOOLCHAIN)-as
MICROKIT_TOOL ?= $(MICROKIT_SDK)/bin/microkit

HELLO_OBJS := hello.o 
HELLO2_OBJS := hello2.o

BOARD_DIR := $(MICROKIT_SDK)/board/$(MICROKIT_BOARD)/$(MICROKIT_CONFIG)


IMAGES := hello.elf hello2.elf
CFLAGS := -mcpu=$(CPU) -mstrict-align -nostdlib -nolibc -ffreestanding -g3 -O3 -Wall -Wno-unused-function -Werror --specs=/home/dstorer/mk-manifest/microkit/example/maaxboard/hello_libc/picolibc/build-aarch64-linux-elf_nocrt2/picolibc.specs -I$(BOARD_DIR)/include  
LDFLAGS := -L$(BOARD_DIR)/lib
LIBS := ${PICOLIBC_DIR}/lib/libm.a  ${PICOLIBC_DIR}/lib/libc.a -lmicrokit -Tmicrokit.ld # /usr/lib/gcc-cross/aarch64-linux-gnu/10/libgcc.a


IMAGE_FILE = $(BUILD_DIR)/loader.img
REPORT_FILE = $(BUILD_DIR)/report.txt

all: $(IMAGE_FILE)

$(BUILD_DIR)/%.o: %.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile
	$(AS) -g3 -mcpu=$(CPU) $< -o $@

$(BUILD_DIR)/hello.elf: $(addprefix $(BUILD_DIR)/, $(HELLO_OBJS) ) 
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

$(BUILD_DIR)/hello2.elf: $(addprefix $(BUILD_DIR)/, $(HELLO2_OBJS) ) 
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

# $(BUILD_DIR)/mem_handler.elf: $(addprefix $(BUILD_DIR)/, $(MEM_OBJS))
# 	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

$(IMAGE_FILE) $(REPORT_FILE): $(addprefix $(BUILD_DIR)/, $(IMAGES)) hello.system
	$(MICROKIT_TOOL) hello.system --search-path $(BUILD_DIR) --board $(MICROKIT_BOARD) --config $(MICROKIT_CONFIG) -o $(IMAGE_FILE) -r $(REPORT_FILE)
