cmake_minimum_required(VERSION 3.10)

project(07_Environmental)

option(READLINE_ENABLED false)

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