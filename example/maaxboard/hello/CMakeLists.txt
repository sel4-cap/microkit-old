cmake_minimum_required(VERSION 3.7.2)

set(CPU cortex-a53)
set(TOOLCHAIN aarch64-linux-gnu)
set(CMAKE_C_COMPILER ${TOOLCHAIN}-gcc)
set(CMAKE_C_COMPILER_WORKS 1)
project(hello-microkit LANGUAGES C)

# set(LD ${TOOLCHAIN}-ld)
# set(CMAKE_ASM_COMPILER ${TOOLCHAIN}-as)

# microkit specific information
#! export to makefile{
set(MICROKIT_SDK /host/mk-manifest/microkit/release/microkit-sdk-1.2.6)
set(MICROKIT_BOARD maaxboard)
set(MICROKIT_CONFIG debug)
# set python variables
set(PYTHONPATH /host/mk-manifest/microkit/tool)
set(MICROKIT_TOOL "python3 -m microkit")

set(BOARD_DIR ${MICROKIT_SDK}/board/${MICROKIT_BOARD}/${MICROKIT_CONFIG})
set(PICOLIBC_DIR /host/mk-manifest/microkit/example/maaxboard/hello/picolibc_build/picolibc/aarch64-linux-gnu)

set(CMAKE_C_FLAGS "-march=armv8-a -D__KERNEL_64__ -g -D_XOPEN_SOURCE=700 -ffreestanding -mstrict-align -fno-common -fno-pic -fno-pie -nostdlib -nolibc -fpic --specs=/host/mk-manifest/microkit/example/maaxboard/hello/picolibc/build-aarch64-linux-elf_nocrt/picolibc.specs" )
  


set(LDFLAGS -L${BOARD_DIR}/lib -nostdlib)
set(LIBS -lmicrokit -Tmicrokit.ld -lgcc -L${PICOLIBC_DIR}/lib -lc -lm -lgcc)

set(BUILD_DIR ${CMAKE_CURRENT_LIST_DIR}/hello-build)
set(IMAGE_FILE ${BUILD_DIR}/loader.img)
set(REPORT_FILE ${BUILD_DIR}/report.txt)

set(libUbootPlatform "maaxboard")

#Add libraries 
add_subdirectory(libmicrokitutils)
add_subdirectory(libubootdrivers)
add_subdirectory(libutils)

add_custom_target(make-img 
    ALL COMMAND bash -c
    "PYTHONPATH=${PYTHONPATH} MICROKIT_SDK=${MICROKIT_SDK} ${MICROKIT_TOOL} ../hello.system --search-path ${BUILD_DIR} --board ${MICROKIT_BOARD} --config ${MICROKIT_CONFIG} -o ${IMAGE_FILE} -r ${REPORT_FILE}")
    
    # COMMAND ${CMAKE_COMMAND} -E env "MICROKIT_SDK=${MICROKIT_SDK} MICROKIT_BOARD=${MICROKIT_BOARD} MICROKIT_CONFIG=debug PYTHONPATH=${PYTHONPATH} MICROKIT_TOOL=${MICROKIT_TOOL}"

add_executable(hello.elf hello.c) 
# add_executable(hello2.elf hello2.c) 


# linker
target_link_options(hello.elf PRIVATE ${LDFLAGS})
target_compile_options(hello.elf PRIVATE ${CFLAGS})
target_include_directories(hello.elf PRIVATE 
    "${BOARD_DIR}/include" 
    "libmicrokitutils/include/"
    "libubootdrivers/include/public_api/"
    "${PICOLIBC_DIR}/include/")
# target_include_directories(hello.elf PRIVATE ${BOARD_DIR}/include)
target_link_libraries(hello.elf PUBLIC ubootdrivers utils libmicrokitutils)
target_link_libraries(hello.elf PRIVATE ${LIBS})

# target_link_options(hello2.elf PRIVATE ${LDFLAGS})
# target_compile_options(hello2.elf PRIVATE ${CFLAGS})
# target_include_directories(hello2.elf PRIVATE ${BOARD_DIR}/include)
# target_link_libraries(hello2.elf PRIVATE ${LIBS})


