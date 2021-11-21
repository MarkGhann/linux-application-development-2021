cmake_minimum_required(VERSION 3.10)

project(08_Regexps)

add_executable(esub esub.c)

add_custom_target( run_tests
        COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/testing
        COMMAND touch ${CMAKE_SOURCE_DIR}/testing/tmp_test_custom.txt
        COMMAND touch ${CMAKE_SOURCE_DIR}/testing/helper.txt

        COMMAND echo "Positive tests"
        COMMAND ${CMAKE_SOURCE_DIR}/pos_tests.sh ${CMAKE_SOURCE_DIR}
        COMMAND echo "tests PASSED"

        COMMAND rm -rf ${CMAKE_SOURCE_DIR}/testing
        DEPENDS esub
)

add_custom_target( build_clean
        COMMAND echo "removing related files from build directory"
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/CMakeCache.txt
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/Makefile
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/cmake_install.cmake
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/esub
        COMMAND echo "build directory cleaned"
)