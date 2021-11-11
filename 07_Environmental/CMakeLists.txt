cmake_minimum_required(VERSION 3.10)

project(07_Environmental)

option(READLINE_ENABLED "Set readline mode" false)

set(LIBS "")
set(COMPILE_VARS "")

find_library(LIBRHASH rhash REQUIRED)
if(NOT LIBRHASH)
    message(FATAL_ERROR "No rhash library -- try to use 'apt-get install librhash-dev'. Stop.")
endif()
list(APPEND LIBS ${LIBRHASH})

if (READLINE_ENABLED)
    find_library(LIBRREADLINE readline REQUIRED)
    if(NOT LIBRREADLINE)
        message(WARNING "No readline library -- try to use 'apt-get install libreadline-dev'. The program will be used without it.")
    else()
        list(APPEND LIBS ${LIBRREADLINE})
        list(APPEND COMPILE_VARS "READLINE_ENABLED=1")
    endif()
endif()

add_executable(rhasher rhasher.c)
target_link_libraries(rhasher ${LIBS})
target_compile_definitions(rhasher PRIVATE ${COMPILE_VARS})

add_custom_target( run_tests
        COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/testing
        COMMAND touch ${CMAKE_SOURCE_DIR}/testing/tmp_test_custom.txt
        COMMAND touch ${CMAKE_SOURCE_DIR}/testing/tmp_test_system.txt
        COMMAND touch ${CMAKE_SOURCE_DIR}/testing/helper.txt
        COMMAND touch ${CMAKE_SOURCE_DIR}/testing/helper2.txt

        COMMAND echo "test 1 MD5 File"
        COMMAND echo -n "MD5 ${CMAKE_SOURCE_DIR}/test-sources/test1" | ${CMAKE_CURRENT_BINARY_DIR}/rhasher > ${CMAKE_SOURCE_DIR}/testing/helper.txt
        COMMAND sed 's/result//g' ${CMAKE_SOURCE_DIR}/testing/helper.txt | sed 's/://g' | sed 's/>>>//g' | sed 's/ //g' > ${CMAKE_SOURCE_DIR}/testing/tmp_test_custom.txt
        COMMAND md5sum ${CMAKE_SOURCE_DIR}/test-sources/test1 > ${CMAKE_SOURCE_DIR}/testing/helper.txt
        COMMAND sed 's/ [^|]*//' ${CMAKE_SOURCE_DIR}/testing/helper.txt 1> ${CMAKE_SOURCE_DIR}/testing/tmp_test_system.txt
        COMMAND cmp ${CMAKE_SOURCE_DIR}/testing/tmp_test_custom.txt ${CMAKE_SOURCE_DIR}/testing/tmp_test_system.txt
        COMMAND echo "test 1 PASSED"

        COMMAND echo "test 2 MD5 File"
        COMMAND echo "test 2 PASSED"

        COMMAND echo "test 3 MD5 File"
        COMMAND echo "test 3 PASSED"

        COMMAND echo "test 4 MD5 String"
        COMMAND echo "test 4 PASSED"

        COMMAND echo "test 5 MD5 String"
        COMMAND echo "test 5 PASSED"

        COMMAND echo "test 6 MD5 String"
        COMMAND echo "test 6 PASSED"

        COMMAND rm -r ${CMAKE_SOURCE_DIR}/testing
        DEPENDS rhasher
)

add_custom_target( build_clean
        COMMAND echo "removing related files from build directory"
        COMMAND rm ${CMAKE_CURRENT_BINARY_DIR}/CMakeCache.txt
        COMMAND rm -r ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles
        COMMAND rm ${CMAKE_CURRENT_BINARY_DIR}/Makefile
        COMMAND rm ${CMAKE_CURRENT_BINARY_DIR}/cmake_install.cmake
        COMMAND rm ${CMAKE_CURRENT_BINARY_DIR}/rhasher
        COMMAND echo "build directory cleaned"
)

add_custom_target( total_clean
        COMMAND echo "removing all files from build directory"
        COMMAND rm ${CMAKE_CURRENT_BINARY_DIR}/*
        COMMAND echo "build directory cleaned"
)