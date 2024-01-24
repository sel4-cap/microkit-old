cmake_minimum_required(VERSION 3.7.2)

set(CPU cortex-a53)
set(TOOLCHAIN aarch64-linux-gnu)
set(CMAKE_C_COMPILER ${TOOLCHAIN}-gcc)
set(CMAKE_C_COMPILER_WORKS 1)
project(uboot-driver-example-microkit LANGUAGES C)

set(LD ${TOOLCHAIN}-ld)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN}-as)
set(MICROKIT_DIR /home/dstorer/docker_test/mk-manifest/microkit/)

# microkit specific information
set(MICROKIT_SDK ${MICROKIT_DIR}/release/microkit-sdk-1.2.6)
set(MICROKIT_BOARD maaxboard)
set(MICROKIT_CONFIG debug)
# set python variables
set(PYTHONPATH ${MICROKIT_DIR}/tool)
set(MICROKIT_TOOL "python3 -m microkit")
# set dtb path
set(DTB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/maaxboard.dtb)

set(BOARD_DIR ${MICROKIT_SDK}/board/${MICROKIT_BOARD}/${MICROKIT_CONFIG})
set(PICOLIBC_DIR ${MICROKIT_DIR}/example/maaxboard/uboot-driver-example/picolibc_build/picolibc/aarch64-linux-gnu)

set(CFLAGS -mcpu=${CPU} "-DDTB_PATH=\"${DTB_PATH}\"" -nostdlib -ffreestanding -Wall -Wno-unused-function)
# -D_XOPEN_SOURCE=700 needed to remove error relating to fls
# set(CMAKE_C_FLAGS "-mcpu=${CPU} -ffreestanding -nostdlib -nolibc" )



set(LDFLAGS -L${BOARD_DIR}/lib -nostdlib)
set(LIBS -lmicrokit -Tmicrokit.ld -lgcc -L${PICOLIBC_DIR}/lib -lc -lm -lgcc)

set(BUILD_DIR ${CMAKE_CURRENT_LIST_DIR}/example-build)
set(IMAGE_FILE ${BUILD_DIR}/sel4test-driver-image-arm-maaxboard.img)
set(REPORT_FILE ${BUILD_DIR}/report.txt)

set(libUbootPlatform "maaxboard")

#Add libraries 
add_subdirectory(libmicrokitutils)
add_subdirectory(libubootdrivers)
add_subdirectory(libutils)

add_custom_target(make-img 
    ALL COMMAND bash -c
    "PYTHONPATH=${PYTHONPATH} MICROKIT_SDK=${MICROKIT_SDK} ${MICROKIT_TOOL} ../uboot-driver-example.system --search-path ${BUILD_DIR} --board ${MICROKIT_BOARD} --config ${MICROKIT_CONFIG} -o ${IMAGE_FILE} -r ${REPORT_FILE}")
    
    # COMMAND ${CMAKE_COMMAND} -E env "MICROKIT_SDK=${MICROKIT_SDK} MICROKIT_BOARD=${MICROKIT_BOARD} MICROKIT_CONFIG=debug PYTHONPATH=${PYTHONPATH} MICROKIT_TOOL=${MICROKIT_TOOL}"

add_executable(uboot-driver-example.elf uboot-driver-example.c)

# linker
target_link_options(uboot-driver-example.elf PRIVATE ${LDFLAGS})
target_compile_options(uboot-driver-example.elf PRIVATE ${CFLAGS})
target_include_directories(uboot-driver-example.elf PRIVATE 
    "${BOARD_DIR}/include" 
    "libmicrokitutils/include/"
    "libubootdrivers/include/public_api/"
    "libubootdrivers/include/wrapper"
    "${PICOLIBC_DIR}/include/")
target_include_directories(uboot-driver-example.elf PRIVATE ${BOARD_DIR}/include)
target_link_libraries(uboot-driver-example.elf PUBLIC ubootdrivers utils libmicrokitutils)
target_link_libraries(uboot-driver-example.elf PRIVATE ${LIBS})



