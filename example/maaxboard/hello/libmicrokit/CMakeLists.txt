cmake_minimum_required(VERSION 3.7.2)

project(printf LANGUAGES C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library(printf SHARED STATIC
    src/dma.c
    src/util.c
)

target_include_directories(printf PRIVATE 
    "${BOARD_DIR}/include" 
    "include/dma/")

# target_include_directories(printf INTERFACE include/public_api)

install(TARGETS printf
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})