cmake_minimum_required(VERSION 3.7.2)

project(printf LANGUAGES C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library(printf SHARED STATIC
    src/printf.c
    src/tinyalloc.c
    src/dma.c
    src/util.c
)

set_target_properties(printf PROPERTIES PUBLIC_HEADER include/stdio.h)
set_target_properties(printf PROPERTIES PUBLIC_HEADER include/stdlib.h)
target_include_directories(printf PRIVATE 
    "${BOARD_DIR}/include" 
    "include/" 
    "include/dma/")

install(TARGETS printf
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})