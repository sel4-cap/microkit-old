cmake_minimum_required(VERSION 3.7.2)

project(printf LANGUAGES C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library(printf SHARED STATIC
    src/public_api.c
    src/dma.c
    src/util.c
    src/printf.c
)

target_include_directories(printf PRIVATE 
    "${BOARD_DIR}/include" 
    "include/" 
    "include/dma/"
    "include/public_api")

target_include_directories(printf INTERFACE include/public_api)

install(TARGETS printf
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})