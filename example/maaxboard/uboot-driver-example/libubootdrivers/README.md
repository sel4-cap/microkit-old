# libubootdrivers

The libubootdrivers library provides a framework for using U-Boot device drivers under seL4. The library provides the necessary stubs, configuration data, and supporting code to allow the use of these drivers with minimal or no modification, as well as an API for interacting with the drivers and essential library functions. The library includes example usage for an extensive set of drivers for the Avnet MaaXBoard, including USB, Ethernet, SD/MMC, I2C, SPI, GPIO, IOMUX, LEDs, Filesystem, and Clock drivers. A smaller set of drivers is also provided for the Odroid-C2 platform, including GPIO and LEDs.

## Library directory structure

The root of the library contains 4 folders and one file as follows:

- include - this folder contains platform-specific configuration data (examples provided for the Avnet MaaXBoard and Odroid-C2) for the drivers, the header file for the public API provided by the library, as well as a number of header files for wrappers around the U-Boot source code.

- src - this folder contains the source code for the library's U-Boot wrappers, its API, supporting code for timer drivers, and additional platform-specific configuration data.

- uboot_stub - this folder provides stubs for various U-Boot source code files that have functions provided instead by the seL4 kernel, including the console, logging, random number generation, and environment variables.

- uboot - this folder contains the entire U-Boot source, cloned from the sel4devkit/uboot repository. The U-Boot source is brought in to provide the driver code as well as code for U-Boot commands, which can be executed via an interface in the library's API. **NOTE: This folder is only added to the libubootdrivers directory when cloned using an appropriate manifest (e.g. sel4devkit/camkes_manifest) with the repo tool.**

- CMakeLists.txt - this file contains much of the base configuration data for the library, including definitions for architecture and platform-specific configuration variables, and settings for the default logging level.

## Platform-specific configuration

Two main files are used to provide specific configuration data for each platform: a C source file and associated header file. These are stored under src/plat/<platform_name> and include/plat/<platform_name> respectively. These files contain information about what drivers and commands should be made available for a platform, based on the driver/command string names from the U-Boot source. They also provide a list of environment variables that should be made available. Examples exist in the library for the Avnet MaaXBoard and the Odroid-C2.

