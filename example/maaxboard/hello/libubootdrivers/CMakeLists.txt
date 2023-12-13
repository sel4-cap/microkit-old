# 
# Copyright 2022 Capgemini Engineering
#
# SPDX-License-Identifier: BSD-2-Clause
#

cmake_minimum_required(VERSION 3.7.2)

project(libubootdrivers C)

# Set the logging level for the library (e.g. ZF_LOG_INFO, ZF_LOG_VERBOSE, etc)
set(LIB_UBOOT_LOGGING_LEVEL "ZF_LOG_INFO")
add_definitions("-DZF_LOG_LEVEL=${LIB_UBOOT_LOGGING_LEVEL}")

# config_option(LibUBOOT LIB_UBOOTB "Build USB interface library" DEFAULT ON)
if(libUbootPlatform STREQUAL "maaxboard")
    set(LibUBOOT ON)
    set(KernelPlatImx8mq ON)
    set(KernelPlatformMaaxboard ON)
    set(KernelArch "arm")
    set(KernelPlatform "maaxboard")
    set(KernelArchARM ON)
    set(Kernel64 ON)
    set(KernelArchArmV8a ON)
    set(KernelArmCacheLineSizeBits "6")
else()
    message(FATAL_ERROR "LibUbootPlatform not set to a defined platform")
endif()

# add_library(ubootdrivers STATIC EXCLUDE_FROM_ALL "")

# add_config_library(ubootdrivers "${configure_string}")
if(LibUBOOT)

    # add_library(ubootdrivers STATIC EXCLUDE_FROM_ALL "")

    ##################################
    # Architecture specific settings #
    ##################################

    if(KernelArchARM)
        # Set architecture as ARM.
        add_definitions("-DCONFIG_ARM")

        # Tell U-Boot code whether this is ARM32 or ARM64. Note that U-Boot
        # code defaults to 32Bit, we only need to explicitly provide definitions
        # to switch to 64Bit addressing.
        if(Kernel64)
            add_definitions("-DCONFIG_ARM64")
            add_definitions("-DCONFIG_DMA_ADDR_T_64BIT")
            add_definitions("-DCONFIG_PHYS_64BIT")
        endif()

        # Tell U-Boot code which generation of ARM we are using.
        if(KernelArchArmV8a)
            add_definitions("-D__LINUX_ARM_ARCH__=8")
        elseif(KernelArchArmV7a OR KernelArchArmV7ve)
            add_definitions("-D__LINUX_ARM_ARCH__=7")
        endif()

        # Tell U-Boot code the processor's cacheline size.
        math(EXPR CACHELINE_SIZE "1 << ${KernelArmCacheLineSizeBits}")
        add_definitions("-DCONFIG_SYS_CACHELINE_SIZE=${CACHELINE_SIZE}")
    endif()

    ##############################
    # Platform specific settings #
    ##############################

    # By default set all of the drivers to use to null / dummy settings.
    set(timer_driver "dummy")
    set(clock_driver "none")
    set(iomux_driver "none")
    set(gpio_driver "none")
    set(eth_driver "none")
    set(eth_phy_driver "none")
    set(usb_driver "none")
    set(usb_phy_driver "none")
    set(mmc_driver "none")
    set(i2c_driver "none")
    set(spi_driver "none")
    set(led_driver "none")
    set(disk_support "false")
    set(usb_storage_support "false")
    set(usb_keyboard_support "false")

    # Set up the applicable drivers and platform dependent configuration.
    if(KernelPlatImx8mq)
        # Platform specific configuration
        add_definitions("-DCONFIG_ARCH_IMX8M=1")
        add_definitions("-DCONFIG_IMX8M=1")
        add_definitions("-DCONFIG_IMX8MQ=1")

        # Define the drivers used for this platform
        set(timer_driver "imx8mq")
        set(clock_driver "imx8mq")
        set(iomux_driver "imx8mq-pinctrl")
        set(gpio_driver "gpio_mxc")
        set(eth_driver "fecmxc")
        set(usb_driver "dwc3_generic")
        set(usb_phy_driver "nxp_imx8mq_usb_phy")
        set(mmc_driver "fsl_esdhc")
        set(i2c_driver "i2c_mxc")
        set(spi_driver "mxc_spi")
        set(led_driver "gpio_led")
        set(disk_support "true")
        set(usb_storage_support "true")
        set(usb_keyboard_support "true")

        # Set the Ethernet PHY based upon the board
        if(KernelPlatformMaaxboard OR KernelPlatformImx8mq-evk)
            set(eth_phy_driver "atheros")
        else()
            message(FATAL_ERROR "Unsupported iMX8MQ board. Aborting.")
        endif()

        # Create a symlink named 'arch' to the platform's headers. This
        # mimics the behaviour of the "CREATE_ARCH_SYMLINK" option within
        # U-Boot's build system (see Makefile.autoconf).
        set(arch_source "./arch-imx8m")
        set(arch_target "../libubootdrivers/uboot/arch/arm/include/asm/arch")
        execute_process(COMMAND ln -fsn ${arch_source} ${arch_target})

    elseif("${KernelPlatform}" STREQUAL "odroidc2")
        # Define the drivers used for this platform
        set(iomux_driver "meson-gxbb-pinctrl")
        set(gpio_driver "meson_gx_gpio_driver")
        set(led_driver "gpio_led")

        # Create a symlink named 'arch' to the platform's headers. This
        # mimics the behaviour of the "CREATE_ARCH_SYMLINK" option within
        # U-Boot's build system (see Makefile.autoconf).
        set(arch_source "./arch-meson")
        set(arch_target "../projects/uboot/arch/arm/include/asm/arch")
        execute_process(COMMAND ln -fsn ${arch_source} ${arch_target})


    else()
        message(FATAL_ERROR "Unsupported platform. Aborting.")
    endif()

    ##############################
    # Settings for timer drivers #
    ##############################

    if(timer_driver MATCHES "dummy")
        list(APPEND uboot_deps src/timer/timer_dummy.c)
    elseif(timer_driver MATCHES "imx8mq")
        list(APPEND uboot_deps src/timer/timer_imx8mq.c)
    else()
        message(FATAL_ERROR "Unrecognised timer driver. Aborting.")
    endif()

    ##############################
    # Settings for clock drivers #
    ##############################

    if(clock_driver MATCHES "none")
        # Nothing to do
    else()
        # Enable clock support
        add_definitions("-DCONFIG_CLK=1")
        add_definitions("-DCONFIG_CLK_CCF=1")
        # Generate clock source files
        list(APPEND uboot_deps uboot/cmd/clk.c)
        list(APPEND uboot_deps uboot/drivers/clk/clk.c)
        list(APPEND uboot_deps uboot/drivers/clk/clk_fixed_factor.c)
        list(APPEND uboot_deps uboot/drivers/clk/clk_fixed_rate.c)
        list(APPEND uboot_deps uboot/drivers/clk/clk-composite.c)
        list(APPEND uboot_deps uboot/drivers/clk/clk-divider.c)
        list(APPEND uboot_deps uboot/drivers/clk/clk-gate.c)
        list(APPEND uboot_deps uboot/drivers/clk/clk-mux.c)
        list(APPEND uboot_deps uboot/drivers/clk/clk-uclass.c)

        if(clock_driver MATCHES "imx8mq")
            list(APPEND uboot_deps uboot/arch/arm/mach-imx/imx8m/clock_imx8mq.c)
            list(APPEND uboot_deps uboot/arch/arm/mach-imx/imx8m/clock_slice.c)
            list(APPEND uboot_deps uboot/drivers/clk/clk-fixed-factor.c)
            list(APPEND uboot_deps uboot/drivers/clk/imx/clk-composite-8m.c)
            list(APPEND uboot_deps uboot/drivers/clk/imx/clk-gate2.c)
            list(APPEND uboot_deps uboot/drivers/clk/imx/clk-imx8mq.c)
            list(APPEND uboot_deps uboot/drivers/clk/imx/clk-pll14xx.c)
        else()
            message(FATAL_ERROR "Unrecognised clock driver. Aborting.")
        endif()
    endif()

    ##############################
    # Settings for IOMUX drivers #
    ##############################

    if(iomux_driver MATCHES "none")
        # Nothing to do
    else()
        # Enable IOMUX support
        add_definitions("-DCONFIG_PINCTRL=1")
        add_definitions("-DCONFIG_PINCTRL_FULL=1")
        add_definitions("-DCONFIG_PINCTRL_GENERIC=1")
        add_definitions("-DCONFIG_PINMUX=1")
        add_definitions("-DCONFIG_PINCONF_RECURSIVE=1")
        # Generic IOMUX source files
        list(APPEND uboot_deps uboot/cmd/pinmux.c)
        list(APPEND uboot_deps uboot/drivers/pinctrl/pinctrl-generic.c)
        list(APPEND uboot_deps uboot/drivers/pinctrl/pinctrl-uclass.c)

        # Driver specific settings / files
        if(iomux_driver MATCHES "imx8mq-pinctrl")
            list(APPEND uboot_deps uboot/drivers/pinctrl/nxp/pinctrl-imx.c)
            list(APPEND uboot_deps uboot/drivers/pinctrl/nxp/pinctrl-imx8m.c)
        elseif(iomux_driver MATCHES "meson-gxbb-pinctrl")
            list(APPEND uboot_deps uboot/drivers/pinctrl/meson/pinctrl-meson-gxbb.c)
            list(APPEND uboot_deps uboot/drivers/pinctrl/meson/pinctrl-meson.c)
            list(APPEND uboot_deps uboot/drivers/pinctrl/meson/pinctrl-meson-gx-pmx.c)
        else()
            message(FATAL_ERROR "Unrecognised IOMUX driver. Aborting.")
        endif()
    endif()

    #############################
    # Settings for GPIO drivers #
    #############################

    if(gpio_driver MATCHES "none")
        # Nothing to do
    else()
        # Enable GPIO support
        add_definitions("-DCONFIG_DM_GPIO=1")
        add_definitions("-DCONFIG_GPIO_EXTRA_HEADER=1")
        add_definitions("-DCONFIG_CMD_GPIO_READ=1")
        # Generic GPIO source files
        list(APPEND uboot_deps uboot/cmd/gpio.c)
        list(APPEND uboot_deps uboot/drivers/gpio/gpio-uclass.c)

        # Driver specific settings / files
        if(gpio_driver MATCHES "gpio_mxc")
            list(APPEND uboot_deps uboot/drivers/gpio/mxc_gpio.c)
        elseif(gpio_driver MATCHES "meson_gx_gpio_driver")
            # This driver is actually supplied by the IOMUX driver; ensure it is active.
            if(NOT iomux_driver MATCHES "meson-gxbb-pinctrl")
                message(FATAL_ERROR "Cannot enable PGIO driver without IOMUX driver. Aborting.")
            endif()
        else()
            message(FATAL_ERROR "Unrecognised GPIO driver. Aborting.")
        endif()
    endif()

    #################################
    # Settings for Ethernet drivers #
    #################################

    if(eth_driver MATCHES "none")
        # Nothing to do
    else()
        # Enable Ethernet support
        add_definitions("-DCONFIG_ETH=1")
        add_definitions("-DCONFIG_NET=1")
        add_definitions("-DCONFIG_DM_ETH=1")
        add_definitions("-DCONFIG_TFTP_BLOCKSIZE=1468")
        add_definitions("-DCONFIG_TFTP_WINDOWSIZE=1")
        add_definitions("-DCONFIG_DM_ETH=1")
        add_definitions("-DCONFIG_CMD_NET=1")
        add_definitions("-DCONFIG_CMD_DNS=1")
        add_definitions("-DCONFIG_CMD_PING=1")
        add_definitions("-DCONFIG_ARP_TIMEOUT=200")
        add_definitions("-DCONFIG_NET_RETRY_COUNT=10")
        # Generic Ethernet source files
        list(APPEND uboot_deps uboot/cmd/net.c)
        list(APPEND uboot_deps uboot/net/arp.c)
        list(APPEND uboot_deps uboot/net/dns.c)
        list(APPEND uboot_deps uboot/net/eth_common.c)
        list(APPEND uboot_deps uboot/net/eth-uclass.c)
        list(APPEND uboot_deps uboot/net/net.c)
        list(APPEND uboot_deps uboot/net/pcap.c)
        list(APPEND uboot_deps uboot/net/ping.c)
        list(APPEND uboot_deps uboot/net/sntp.c)
        list(APPEND uboot_deps uboot/net/tftp.c)
        list(APPEND uboot_deps uboot/net/udp.c)

        # Driver specific settings / files
        if(eth_driver MATCHES "fecmxc")
            add_definitions("-DCONFIG_PHYLIB=1")
            add_definitions("-DCONFIG_FEC_MXC=1")
            add_definitions("-DCONFIG_MII=1")
            add_definitions("-DCONFIG_NET_RANDOM_ETHADDR=1")

            list(APPEND uboot_deps uboot/arch/arm/mach-imx/mac.c)
            list(APPEND uboot_deps uboot/common/miiphyutil.c)
            # list(APPEND uboot_deps uboot/drivers/net/fec_mxc.c)
        else()
            message(FATAL_ERROR "Unrecognised Ethernet driver. Aborting.")
        endif()
    endif()

    #####################################
    # Settings for Ethernet PHY drivers #
    #####################################

    if(eth_phy_driver MATCHES "none")
        # Nothing to do
    elseif (eth_driver MATCHES "none")
        message(FATAL_ERROR "Cannot enable Ethernet PHY driver without Ethernet driver. Aborting.")
    elseif(eth_phy_driver MATCHES "atheros")
        add_definitions("-DCONFIG_PHY_ATHEROS=1")
        add_definitions("-DCONFIG_PHY_GIGE=1")
        list(APPEND uboot_deps uboot/drivers/net/phy/atheros.c)
        list(APPEND uboot_deps uboot/drivers/net/phy/phy.c)
    else()
        message(FATAL_ERROR "Unrecognised Ethernet PHY driver. Aborting.")
    endif()

    ############################
    # Settings for USB drivers #
    ############################

    if(usb_driver MATCHES "none")
        # Nothing to do
    else()
        # Variable to control which USB stack to use
        set(usb_stack "none")

        # Enable USB support
        add_definitions("-DCONFIG_DM_USB=1")
        add_definitions("-DCONFIG_USB_HOST=1")
        add_definitions("-DCONFIG_SYS_USB_EVENT_POLL=1")

        # Generic USB source files
        list(APPEND uboot_deps uboot/cmd/usb.c)
        list(APPEND uboot_deps uboot/common/usb_hub.c)
        list(APPEND uboot_deps uboot/common/usb.c)
        list(APPEND uboot_deps uboot/drivers/usb/common/common.c)
        list(APPEND uboot_deps uboot/drivers/usb/gadget/udc/udc-core.c)
        list(APPEND uboot_deps uboot/drivers/usb/host/usb-uclass.c)

        # Driver specific settings / files
        if(usb_driver MATCHES "dwc3_generic")
            # This is an XCHI device
            set(usb_stack "xhci")

            add_definitions("-DCONFIG_USB_XHCI_DWC3=1")

            list(APPEND uboot_deps uboot/drivers/usb/dwc3/core.c)
            list(APPEND uboot_deps uboot/drivers/usb/dwc3/dwc3-generic.c)
            list(APPEND uboot_deps uboot/drivers/usb/dwc3/ep0.c)
        else()
            message(FATAL_ERROR "Unrecognised USB driver. Aborting.")
        endif()

        # Set up the chosen USB stack
        if(usb_stack MATCHES "xhci")
            add_definitions("-DCONFIG_USB_XHCI_HCD=1")
            list(APPEND uboot_deps uboot/drivers/usb/host/xhci-mem.c)
            list(APPEND uboot_deps uboot/drivers/usb/host/xhci-ring.c)
            list(APPEND uboot_deps uboot/drivers/usb/host/xhci.c)
        else()
            message(FATAL_ERROR "No USB stack selected. Aborting.")
        endif()

    endif()

    ################################
    # Settings for USB PHY drivers #
    ################################

    if(usb_phy_driver MATCHES "none")
        # Nothing to do
    elseif (usb_driver MATCHES "none")
        message(FATAL_ERROR "Cannot enable USB PHY driver without USB driver. Aborting.")
    elseif(usb_phy_driver MATCHES "nxp_imx8mq_usb_phy")
        list(APPEND uboot_deps uboot/drivers/phy/phy-imx8mq-usb.c)
    else()
        message(FATAL_ERROR "Unrecognised USB PHY driver. Aborting.")
    endif()

    ############################
    # Settings for MMC drivers #
    ############################

    if(mmc_driver MATCHES "none")
        # Nothing to do
    else()
        # Enable MMC support
        add_definitions("-DCONFIG_MMC=1")
        add_definitions("-DCONFIG_DM_MMC=1")
        add_definitions("-DCONFIG_MMC_VERBOSE=1")
        add_definitions("-DCONFIG_MMC_QUIRKS=1")
        add_definitions("-DCONFIG_MMC_WRITE=1")
        add_definitions("-DCONFIG_MMC_HW_PARTITIONING=1")
        add_definitions("-DCONFIG_MMC_IO_VOLTAGE=1")
        # Generic MMC source files
        list(APPEND uboot_deps uboot/cmd/mmc.c)
        list(APPEND uboot_deps uboot/drivers/mmc/mmc_write.c)
        list(APPEND uboot_deps uboot/drivers/mmc/mmc-uclass.c)
        list(APPEND uboot_deps uboot/drivers/mmc/mmc.c)

        # Driver specific settings / files
        if(mmc_driver MATCHES "fsl_esdhc")
            # Config for platform specifc capabilities
            if(KernelPlatImx8mq)
                add_definitions("-DCONFIG_FSL_ESDHC_IMX=1")
                add_definitions("-DCONFIG_FSL_USDHC=1")
                add_definitions("-DCONFIG_MMC_UHS_SUPPORT=1")
                add_definitions("-DCONFIG_MMC_HS200_SUPPORT=1")
                add_definitions("-DCONFIG_MMC_HS400_SUPPORT=1")
            else()
                message(FATAL_ERROR "Unrecognised MMC ESDHC platform. Aborting.")
            endif()

            # list(APPEND uboot_deps uboot/drivers/mmc/fsl_esdhc_imx.c)
        else()
            message(FATAL_ERROR "Unrecognised MMC driver. Aborting.")
        endif()
    endif()

    ############################
    # Settings for I2C drivers #
    ############################

    if(i2c_driver MATCHES "none")
        # Nothing to do
    else()
        # Enable I2C support
        add_definitions("-DCONFIG_CMD_I2C=1")
        add_definitions("-DCONFIG_DM_I2C=1")
        # Generic I2C source files
        list(APPEND uboot_deps uboot/cmd/i2c.c)
        list(APPEND uboot_deps uboot/drivers/i2c/i2c-uclass.c)

        # Driver specific settings / files
        if(i2c_driver MATCHES "i2c_mxc")
            add_definitions("-DCONFIG_SYS_I2C_MXC=1")
            add_definitions("-DCONFIG_SYS_I2C_MXC_I2C1=1")
            add_definitions("-DCONFIG_SYS_I2C_MXC_I2C2=1")
            add_definitions("-DCONFIG_SYS_I2C_MXC_I2C3=1")
            add_definitions("-DCONFIG_SYS_I2C_MXC_I2C4=1")
            add_definitions("-DCONFIG_SYS_MXC_I2C1_SPEED=100000")
            add_definitions("-DCONFIG_SYS_MXC_I2C1_SLAVE=0")
            add_definitions("-DCONFIG_SYS_MXC_I2C2_SPEED=100000")
            add_definitions("-DCONFIG_SYS_MXC_I2C2_SLAVE=0")
            add_definitions("-DCONFIG_SYS_MXC_I2C3_SPEED=100000")
            add_definitions("-DCONFIG_SYS_MXC_I2C3_SLAVE=0")
            add_definitions("-DCONFIG_SYS_MXC_I2C4_SPEED=100000")
            add_definitions("-DCONFIG_SYS_MXC_I2C4_SLAVE=0")

            list(APPEND uboot_deps uboot/drivers/i2c/mxc_i2c.c)
        else()
            message(FATAL_ERROR "Unrecognised I2C driver. Aborting.")
        endif()
    endif()

    ############################
    # Settings for SPI drivers #
    ############################

    if(spi_driver MATCHES "none")
        # Nothing to do
    else()
        # Enable SPI support
        add_definitions("-DCONFIG_DM_SPI_FLASH=1")
        add_definitions("-DCONFIG_DM_SPI=1")
        add_definitions("-DCONFIG_SPI=1")
        add_definitions("-DCONFIG_SPI_FLASH=1")
        add_definitions("-DCONFIG_SPI_FLASH_BAR=1")
        add_definitions("-DCONFIG_SPI_FLASH_STMICRO=1")
        add_definitions("-DCONFIG_DEFAULT_SPI_MODE=0")
        add_definitions("-DCONFIG_DEFAULT_SPI_BUS=0")
        # Generic SPI source files
        list(APPEND uboot_deps uboot/cmd/spi.c)
        list(APPEND uboot_deps uboot/drivers/spi/spi-mem.c)
        list(APPEND uboot_deps uboot/drivers/spi/spi-uclass.c)

        # Driver specific settings / files
        if(spi_driver MATCHES "mxc_spi")
            list(APPEND uboot_deps uboot/drivers/spi/mxc_spi.c)
        else()
            message(FATAL_ERROR "Unrecognised SPI driver. Aborting.")
        endif()
    endif()

    ############################
    # Settings for LED drivers #
    ############################

    if(led_driver MATCHES "none")
        # Nothing to do
    else()
        # Generic LED source files
        list(APPEND uboot_deps uboot/cmd/led.c)
        list(APPEND uboot_deps uboot/drivers/led/led-uclass.c)

        # Driver specific settings / files
        if(led_driver MATCHES "gpio_led")
            if(gpio_driver MATCHES "none")
                message(FATAL_ERROR "Cannot enable LED GPIO driver without GPIO driver. Aborting.")
            endif()
            list(APPEND uboot_deps uboot/drivers/led/led_gpio.c)
        else()
            message(FATAL_ERROR "Unrecognised LED driver. Aborting.")
        endif()
    endif()

    #############################
    # Settings for disk support #
    #############################

    if (disk_support MATCHES "false")
        # Nothing to do
    elseif(disk_support MATCHES "true")
        # Enabled partition support
        add_definitions("-DCONFIG_HAVE_BLOCK_DEVICE=1")
        add_definitions("-DCONFIG_PARTITIONS=1")
        add_definitions("-DCONFIG_PARTITION_UUIDS=1")
        add_definitions("-DCONFIG_PARTITION_TYPE_GUID=1")
        add_definitions("-DONFIG_LIB_UUID=1")
        # Enable partition table support
        add_definitions("-DCONFIG_DOS_PARTITION=1")
        add_definitions("-DCONFIG_EFI_PARTITION=1")
        add_definitions("-DCONFIG_EFI_PARTITION_ENTRIES_NUMBERS=64")
        add_definitions("-DCONFIG_ISO_PARTITION=1")
        add_definitions("-DCONFIG_MAC_PARTITION=1")
        # Enable FAT filesystem support
        add_definitions("-DCONFIG_FS_FAT=1")
        add_definitions("-DCONFIG_FAT_WRITE=1")
        add_definitions("-DCONFIG_FS_FAT_MAX_CLUSTSIZE=65536")
        # Enable EXT filesystem support
        add_definitions("-DCONFIG_FS_EXT4=1")
        add_definitions("-DCONFIG_EXT4_WRITE=1")
        add_definitions("-DCONFIG_CMD_EXT4_WRITE=1")
        # Add srouce files
        list(APPEND uboot_deps uboot/cmd/ext2.c)
        list(APPEND uboot_deps uboot/cmd/ext4.c)
        list(APPEND uboot_deps uboot/cmd/fat.c)
        list(APPEND uboot_deps uboot/cmd/part.c)
        list(APPEND uboot_deps uboot/disk/part_dos.c)
        list(APPEND uboot_deps uboot/disk/part_efi.c)
        list(APPEND uboot_deps uboot/disk/part_iso.c)
        list(APPEND uboot_deps uboot/disk/part_mac.c)
        list(APPEND uboot_deps uboot/disk/part.c)
        list(APPEND uboot_deps uboot/fs/ext4/dev.c)
        list(APPEND uboot_deps uboot/fs/ext4/ext4_common.c)
        list(APPEND uboot_deps uboot/fs/ext4/ext4_journal.c)
        list(APPEND uboot_deps uboot/fs/ext4/ext4_write.c)
        list(APPEND uboot_deps uboot/fs/ext4/ext4fs.c)
        list(APPEND uboot_deps uboot/fs/fat/fat_write.c)
        list(APPEND uboot_deps uboot/fs/fs.c)
        list(APPEND uboot_deps uboot/fs/fs_internal.c)
        list(APPEND uboot_deps uboot/lib/uuid.c)
    else()
        message(FATAL_ERROR "Unrecognised disk support level. Aborting.")
    endif()

    #########################################
    # Settings for USB mass storage support #
    #########################################

    if (usb_storage_support MATCHES "false")
        # Nothing to do
    elseif(usb_storage_support MATCHES "true")
        if(usb_driver MATCHES "none")
            message(FATAL_ERROR "Cannot enable USB mass storage without USB driver. Aborting.")
        endif()
        # Enabled support
        add_definitions("-DCONFIG_USB_STORAGE=1")
        # Add srouce files
        list(APPEND uboot_deps uboot/common/usb_storage.c)
    else()
        message(FATAL_ERROR "Unrecognised USB mass storage support level. Aborting.")
    endif()

    #####################################
    # Settings for USB keyboard support #
    #####################################

    if (usb_keyboard_support MATCHES "false")
        # Nothing to do
    elseif(usb_keyboard_support MATCHES "true")
        if(usb_driver MATCHES "none")
            message(FATAL_ERROR "Cannot enable USB keyboard without USB driver. Aborting.")
        endif()
        # Enabled support
        add_definitions("-DCONFIG_USB_KEYBOARD=1")
        # Add srouce files
        list(APPEND uboot_deps uboot/common/usb_kbd.c)
        list(APPEND uboot_deps uboot/drivers/input/keyboard-uclass.c)
    else()
        message(FATAL_ERROR "Unrecognised USB keyboard support level. Aborting.")
    endif()


    ######################################################
    # Complete configuration of source and include files #
    ######################################################

    # Pull in the base source files used by all platforms
    list(APPEND uboot_deps uboot/env/attr.c)
    list(APPEND uboot_deps uboot/env/callback.c)
    list(APPEND uboot_deps uboot/env/common.c)
    list(APPEND uboot_deps uboot/env/env.c)
    list(APPEND uboot_deps uboot/env/flags.c)
    list(APPEND uboot_deps uboot/lib/crc16.c)
    list(APPEND uboot_deps uboot/lib/crc32.c)
    list(APPEND uboot_deps uboot/lib/ctype.c)
    list(APPEND uboot_deps uboot/lib/date.c)
    list(APPEND uboot_deps uboot/lib/display_options.c)
    list(APPEND uboot_deps uboot/lib/div64.c)
    list(APPEND uboot_deps uboot/lib/fdtdec_common.c)
    list(APPEND uboot_deps uboot/lib/fdtdec.c)
    list(APPEND uboot_deps uboot/lib/hashtable.c)
    list(APPEND uboot_deps uboot/lib/hexdump.c)
    list(APPEND uboot_deps uboot/lib/linux_compat.c)
    list(APPEND uboot_deps uboot/lib/linux_string.c)
    list(APPEND uboot_deps uboot/lib/net_utils.c)
    list(APPEND uboot_deps uboot/lib/of_live.c)
    list(APPEND uboot_deps uboot/lib/string.c)
    list(APPEND uboot_deps uboot/lib/strto.c)
    list(APPEND uboot_deps uboot/lib/vsprintf.c)
    file(GLOB_RECURSE glob_result uboot/lib/libfdt/*.c)
    list(APPEND uboot_deps ${glob_result})
    list(APPEND uboot_deps uboot/cmd/blk_common.c)
    list(APPEND uboot_deps uboot/cmd/dm.c)
    list(APPEND uboot_deps uboot/cmd/nvedit.c)
    list(APPEND uboot_deps uboot/common/cli_readline.c)
    list(APPEND uboot_deps uboot/common/cli_simple.c)
    list(APPEND uboot_deps uboot/common/cli.c)
    list(APPEND uboot_deps uboot/common/command.c)
    list(APPEND uboot_deps uboot/common/fdt_support.c)
    list(APPEND uboot_deps uboot/common/stdio.c)
    list(APPEND uboot_deps uboot/disk/disk-uclass.c)
    list(APPEND uboot_deps uboot/drivers/block/blk-uclass.c)
    list(APPEND uboot_deps uboot/drivers/core/device-remove.c)
    list(APPEND uboot_deps uboot/drivers/core/device.c)
    list(APPEND uboot_deps uboot/drivers/core/devres.c)
    list(APPEND uboot_deps uboot/drivers/core/dump.c)
    list(APPEND uboot_deps uboot/drivers/core/fdtaddr.c)
    list(APPEND uboot_deps uboot/drivers/core/lists.c)
    list(APPEND uboot_deps uboot/drivers/core/of_access.c)
    list(APPEND uboot_deps uboot/drivers/core/of_addr.c)
    list(APPEND uboot_deps uboot/drivers/core/ofnode.c)
    list(APPEND uboot_deps uboot/drivers/core/read.c)
    list(APPEND uboot_deps uboot/drivers/core/root.c)
    list(APPEND uboot_deps uboot/drivers/core/simple-bus.c)
    list(APPEND uboot_deps uboot/drivers/core/uclass.c)
    list(APPEND uboot_deps uboot/drivers/phy/phy-uclass.c)
    file(GLOB_RECURSE glob_result uboot_stub/*.c)
    list(APPEND uboot_deps ${glob_result})
    # file(GLOB_RECURSE wrapper_deps src/wrapper/*.c)
    list(APPEND uboot_deps src/wrapper/uboot_wrapper.c)
    list(APPEND uboot_deps src/wrapper/unimplemented.c)
    # list(APPEND uboot_deps src/wrapper/sel4_io_map.c)
    # list(APPEND uboot_deps src/wrapper/uboot_drivers.c)
    # list(APPEND uboot_deps src/wrapper/sel4_dma.c)
    list(APPEND uboot_deps src/wrapper/sel4_delay.c)
    file(GLOB_RECURSE plat_deps src/plat/${KernelPlatform}/*.c)

    # For all U-Boot source code we:
    # - Add the 'uboot_helper.h' include to provide required includes and configuration.
    # - Silence warnings as performed by the U-Boot build system.
    set_source_files_properties(${uboot_deps} PROPERTIES COMPILE_FLAGS
        "-include uboot_helper.h -Wno-address-of-packed-member")

    # Generate the final list of source files.
    list(APPEND deps ${wrapper_deps})
    list(APPEND deps ${uboot_deps})
    list(APPEND deps ${plat_deps})
    list(SORT deps)
    # target_sources(ubootdrivers PRIVATE ${deps})
    add_library(ubootdrivers STATIC ${deps})

    

    target_include_directories(ubootdrivers PRIVATE
        # U-Boot includes (Include 'stub' first to ensure they override U-Boot includes)
        uboot_stub/include
        uboot/include
        # Added to add libfdt.h
        uboot/scripts/dtc/libfdt
        uboot_stub/arch/${KernelArch}/include
        uboot/arch/${KernelArch}/include
        uboot/lib
        # Includes from the library wrapper
        include/wrapper
        # Platform specific includes
        include/plat/${KernelPlatform}
        "${BOARD_DIR}/include"
        ../libmicrokit/include
    )

    # Declare the public interface to the library.
    target_include_directories(ubootdrivers INTERFACE ../libmicrokit/include)

    # target_link_libraries(ubootdrivers sel4 muslc sel4platsupport utils)
    target_link_libraries(ubootdrivers utils printf)

    #########################
    # Manage logging levels #
    #########################

    # Provide a mapping between the seL4 logging level and the U-Boot logging level
    if("${LIB_UBOOT_LOGGING_LEVEL}" STREQUAL "ZF_LOG_VERBOSE")
        add_definitions("-DCONFIG_LOGLEVEL=9")
    elseif("${LIB_UBOOT_LOGGING_LEVEL}" STREQUAL "ZF_LOG_DEBUG")
        add_definitions("-DCONFIG_LOGLEVEL=8")
    elseif("${LIB_UBOOT_LOGGING_LEVEL}" STREQUAL "ZF_LOG_INFO")
        add_definitions("-DCONFIG_LOGLEVEL=6")
    elseif("${LIB_UBOOT_LOGGING_LEVEL}" STREQUAL "ZF_LOG_WARN")
        add_definitions("-DCONFIG_LOGLEVEL=4")
    elseif("${LIB_UBOOT_LOGGING_LEVEL}" STREQUAL "ZF_LOG_ERROR")
        add_definitions("-DCONFIG_LOGLEVEL=3")
    elseif("${LIB_UBOOT_LOGGING_LEVEL}" STREQUAL "ZF_LOG_FATAL")
        add_definitions("-DCONFIG_LOGLEVEL=0")
    else()
        message(FATAL_ERROR "No recognised logging level set in LIB_UBOOT_LOGGING_LEVEL. Aborting.")
    endif()

endif()
