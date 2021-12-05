cmake_minimum_required(VERSION 3.10)

project(10_I18n)

add_executable(100 100.c)

add_custom_target( build_clean
        COMMAND echo "removing related files from build directory"
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/CMakeCache.txt
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/100
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/Makefile
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/cmake_install.cmake
        COMMAND echo "build directory cleaned"
)