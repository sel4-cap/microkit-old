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

ifeq ($(strip $(MICROKIT_DIR)),)
$(error MICROKIT_DIR must be specified)
endif

ifeq ($(strip $(UBOOT_DIR)),)
$(error UBOOT_DIR must be specified)
endif

TOOLCHAIN := aarch64-none-elf

CPU := cortex-a53

CC := $(TOOLCHAIN)-gcc
LD := $(TOOLCHAIN)-ld
AS := $(TOOLCHAIN)-as
MICROKIT_TOOL ?= $(MICROKIT_SDK)/bin/microkit

UTILS				:= 	tinyalloc.o printf.o util.o timer.o

# XHCI_STUB_OBJS 		:=  xhci_stub.o $(NETBSD_SRC) imx8mq_usbphy.o dwc3_fdt.o shared_ringbuffer.o $(UTILS)
# SOFTWARE_OBJS 		:=  software_interrupts.o $(NETBSD_SRC) $(UTILS) shared_ringbuffer.o
# HARDWARE_OBJS 		:=  hardware_interrupts.o sel4_bus_funcs.o $(UTILS)
# MEM_OBJS			:=  mem_handler.o tinyalloc.o printf.o
# KBD_LOGGER_OBJS 	:=  kbd_logger.o hidkbdmap.o shared_ringbuffer.o printf.o tinyalloc.o
# SIMULATED_KBD_OBJS	:=  simulated_kbd.o printf.o tinyalloc.o

DISPLAY_CONTROLLER_OBJS := xhci_stub.o imx8m_dcss.o imx8m_hdmi.o $(UTILS)

BOARD_DIR := $(MICROKIT_SDK)/board/$(MICROKIT_BOARD)/$(MICROKIT_CONFIG)

# IMAGES := xhci_stub.elf hardware.elf software.elf mem_handler.elf kbd_logger.elf simulated_kbd.elf
IMAGES := display_controller.elf
# INC := $(BOARD_DIR)/include include/tinyalloc include/wrapper include/bus include/dma include/printf include/timer src/
INC := $(BOARD_DIR)/include include/tinyalloc include/wrapper include/bus include/dma include/printf include/timer src/ include/display
INC_PARAMS=$(foreach d, $(INC), -I$d)
WARNINGS := -Wall -Wno-comment -Wno-return-type -Wno-unused-function -Wno-unused-value -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-label -Wno-pointer-sign
CFLAGS := -mcpu=$(CPU) -mstrict-align -ffreestanding -g3 -O3 $(WARNINGS) $(INC_PARAMS) -I$(BOARD_DIR)/include -DSEL4  -DSEL4_USB_DEBUG
LDFLAGS := -L$(BOARD_DIR)/lib
LIBS := -lmicrokit -Tmicrokit.ld

IMAGE_FILE = $(BUILD_DIR)/loader.img
REPORT_FILE = $(BUILD_DIR)/report.txt

# all: includes

all: $(IMAGE_FILE)

# includes:
# 	@mkdir -p ${NETBSD_DIR}/mach_include/machine
# 	@ln -fs ${NETBSD_DIR}/sys/arch/evbarm/include/* $(NETBSD_DIR)/mach_include/machine/
# 	@mkdir -p ${NETBSD_DIR}/mach_include/arm
# 	@ln -fs ${NETBSD_DIR}/sys/arch/arm/include/* $(NETBSD_DIR)/mach_include/arm/
# 	@mkdir -p ${NETBSD_DIR}/mach_include/aarch64
# 	@ln -fs ${NETBSD_DIR}/sys/arch/arm/include/* $(NETBSD_DIR)/mach_include/aarch64/

$(BUILD_DIR)/%.o: src/%.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/%.o: cap/%.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/imx8m_dcss.o: $(UBOOT_DIR)/drivers/video/nxp/imx/imx8m_dcss.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/imx8m_hdmi.o: $(UBOOT_DIR)/drivers/video/nxp/imx/hdmi/imx8m_hdmi.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@
	
$(BUILD_DIR)/%.o: %.s Makefile
	$(AS) -g3 -mcpu=$(CPU) $< -o $@

$(BUILD_DIR)/display_controller.elf: $(addprefix $(BUILD_DIR)/, $(DISPLAY_CONTROLLER_OBJS))
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@


$(IMAGE_FILE) $(REPORT_FILE): $(addprefix $(BUILD_DIR)/, $(IMAGES)) display_driver.system
	$(MICROKIT_TOOL) display_driver.system --search-path $(BUILD_DIR) --board $(MICROKIT_BOARD) --config $(MICROKIT_CONFIG) -o $(IMAGE_FILE) -r $(REPORT_FILE)

# clean
clean:
	rm -f *.o *.elf .depend*
	find . -name \*.o |xargs --no-run-if-empty rm
