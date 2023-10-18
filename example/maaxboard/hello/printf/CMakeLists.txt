cmake_minimum_required(VERSION 3.7.2)

project(printf LANGUAGES C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library(printf SHARED STATIC
    printf.c
)

set_target_properties(printf PROPERTIES PUBLIC_HEADER include/printf.h)
target_include_directories(printf PRIVATE ${BOARD_DIR}/include "include/printf")

install(TARGETS printf
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})