#
# Copyright 2021, Breakaway Consulting Pty. Ltd.
#
# SPDX-License-Identifier: BSD-2-Clause
#
ifeq ($(strip $(BUILD_DIR)),)
$(error BUILD_DIR must be specified)
endif

ifeq ($(strip $(SEL4CP_SDK)),)
$(error SEL4CP_SDK must be specified)
endif

ifeq ($(strip $(SEL4CP_BOARD)),)
$(error SEL4CP_BOARD must be specified)
endif

ifeq ($(strip $(SEL4CP_CONFIG)),)
$(error SEL4CP_CONFIG must be specified)
endif

TOOLCHAIN := aarch64-none-elf

NETBSD_DIR := /home/jfelmeden/cp/sel4cp/example/maaxboard/xhci_stub/netbsd
# ddd: ${NETBSD_DIR}/src/sys/machine

CPU := cortex-a53

CC := $(TOOLCHAIN)-gcc
LD := $(TOOLCHAIN)-ld
AS := $(TOOLCHAIN)-as
SEL4CP_TOOL ?= $(SEL4CP_SDK)/bin/sel4cp

NETBSD_SRC			:=  dev_verbose.o subr_device.o subr_autoconf.o usbdi_util.o usbdi.o usbroothub.o sel4_bus_funcs.o dma.o usb.o usb_quirks.o usb_subr.o xhci.o usb_mem.o uhub.o hid.o uhidev.o ukbd.o ums.o uts.o hidms.o hidkbdmap.o ioconf.o tpcalib.o uhid.o # ugen.o umass.o umass_quirks.o umass_scsipi.o tty_subr.o kern_event.o sys_select.o //not implemented yet
UTILS				:= 	tinyalloc.o printf.o util.o timer.o

XHCI_STUB_OBJS 		:=  xhci_stub.o $(NETBSD_SRC) imx8mq_usbphy.o dwc3_fdt.o shared_ringbuffer.o $(UTILS)
PIPE_HANDLE_OBJS 	:=  pipe_handler.o $(NETBSD_SRC) $(UTILS) shared_ringbuffer.o
# TIMER_OBJS 		:=  timer.o subr_device.o imx8mq_usbphy.o usbdi_util.o usbdi.o usbroothub.o sel4_bus_funcs.o tinyalloc.o dwc3_fdt.o printf.o dma.o usb.o usb_quirks.o usb_subr.o xhci.o usb_mem.o util.o uhub.o
SOFTWARE_OBJS 		:=  software_interrupts.o $(NETBSD_SRC) $(UTILS) shared_ringbuffer.o
HARDWARE_OBJS 		:=  hardware_interrupts.o sel4_bus_funcs.o $(UTILS)
MEM_OBJS			:=  mem_handler.o tinyalloc.o printf.o
KBD_LOGGER_OBJS 	:=  kbd_logger.o hidkbdmap.o shared_ringbuffer.o printf.o tinyalloc.o
SIMULATED_KBD_OBJS	:=  simulated_kbd.o printf.o tinyalloc.o

BOARD_DIR := $(SEL4CP_SDK)/board/$(SEL4CP_BOARD)/$(SEL4CP_CONFIG)

IMAGES := xhci_stub.elf hardware.elf pipe_handler.elf software.elf mem_handler.elf kbd_logger.elf simulated_kbd.elf
INC := $(BOARD_DIR)/include include/tinyalloc include/wrapper netbsd/sys netbsd/mach_include include/bus include/dma include/printf include/timer src/
INC_PARAMS=$(foreach d, $(INC), -I$d)
WARNINGS := -Wall -Wno-comment -Wno-return-type -Wno-unused-function -Wno-unused-value -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-label -Wno-pointer-sign
CFLAGS := -mcpu=$(CPU) -mstrict-align -ffreestanding -g3 -O3 $(WARNINGS) $(INC_PARAMS) -I$(BOARD_DIR)/include -DSEL4  #-DSEL4_USB_DEBUG
LDFLAGS := -L$(BOARD_DIR)/lib
LIBS := -lsel4cp -Tsel4cp.ld

IMAGE_FILE = $(BUILD_DIR)/loader.img
REPORT_FILE = $(BUILD_DIR)/report.txt

all: includes

all: $(IMAGE_FILE)

includes:
	@mkdir -p ${NETBSD_DIR}/mach_include/machine
	@ln -fs ${NETBSD_DIR}/sys/arch/evbarm/include/* netbsd/mach_include/machine/
	@mkdir -p ${NETBSD_DIR}/mach_include/arm
	@ln -fs ${NETBSD_DIR}/sys/arch/arm/include/* netbsd/mach_include/arm/
	@mkdir -p ${NETBSD_DIR}/mach_include/aarch64
	@ln -fs ${NETBSD_DIR}/sys/arch/arm/include/* netbsd/mach_include/aarch64/

$(BUILD_DIR)/%.o: src/%.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/%.o: cap/%.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/usb.o: netbsd/sys/dev/usb/usb.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/usbdi.o: netbsd/sys/dev/usb/usbdi.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/usbdi_util.o: netbsd/sys/dev/usb/usbdi_util.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/usb_mem.o: netbsd/sys/dev/usb/usb_mem.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/usb_quirks.o: netbsd/sys/dev/usb/usb_quirks.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/usb_subr.o: netbsd/sys/dev/usb/usb_subr.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/usbroothub.o: netbsd/sys/dev/usb/usbroothub.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/uts.o: netbsd/sys/dev/usb/uts.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/uhid.o: netbsd/sys/dev/usb/uhid.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/uhidev.o: netbsd/sys/dev/usb/uhidev.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/uhub.o: netbsd/sys/dev/usb/uhub.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/ukbd.o: netbsd/sys/dev/usb/ukbd.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/ums.o: netbsd/sys/dev/usb/ums.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/xhci.o: netbsd/sys/dev/usb/xhci.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/subr_autoconf.o: netbsd/sys/kern/subr_autoconf.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/subr_device.o: netbsd/sys/kern/subr_device.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/kern_pmf.o: netbsd/sys/kern/kern_pmf.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/hid.o: netbsd/sys/dev/hid/hid.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/hidkbdmap.o: netbsd/sys/dev/hid/hidkbdmap.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/hidms.o: netbsd/sys/dev/hid/hidms.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/dev_verbose.o: netbsd/sys/dev/dev_verbose.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/dwc3_fdt.o: netbsd/sys/dev/fdt/dwc3_fdt.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/imx8mq_usbphy.o: netbsd/sys/arch/arm/nxp/imx8mq_usbphy.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/tpcalib.o: netbsd/sys/dev/wscons/tpcalib.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

	
$(BUILD_DIR)/%.o: %.s Makefile
	$(AS) -g3 -mcpu=$(CPU) $< -o $@

$(BUILD_DIR)/mem_handler.elf: $(addprefix $(BUILD_DIR)/, $(MEM_OBJS))
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

$(BUILD_DIR)/software.elf: $(addprefix $(BUILD_DIR)/, $(SOFTWARE_OBJS))
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

$(BUILD_DIR)/xhci_stub.elf: $(addprefix $(BUILD_DIR)/, $(XHCI_STUB_OBJS))
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

$(BUILD_DIR)/hardware.elf: $(addprefix $(BUILD_DIR)/, $(HARDWARE_OBJS))
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

$(BUILD_DIR)/pipe_handler.elf: $(addprefix $(BUILD_DIR)/, $(PIPE_HANDLE_OBJS))
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

$(BUILD_DIR)/kbd_logger.elf: $(addprefix $(BUILD_DIR)/, $(KBD_LOGGER_OBJS))
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

$(BUILD_DIR)/simulated_kbd.elf: $(addprefix $(BUILD_DIR)/, $(SIMULATED_KBD_OBJS))
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

$(IMAGE_FILE) $(REPORT_FILE): $(addprefix $(BUILD_DIR)/, $(IMAGES)) xhci_stub.system
	$(SEL4CP_TOOL) xhci_stub.system --search-path $(BUILD_DIR) --board $(SEL4CP_BOARD) --config $(SEL4CP_CONFIG) -o $(IMAGE_FILE) -r $(REPORT_FILE)

# clean
clean:
	rm -f *.o *.elf .depend*
	find . -name \*.o |xargs --no-run-if-empty rm