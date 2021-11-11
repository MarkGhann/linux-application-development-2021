cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(07_Environmental)

find_library(LIBRHASH rhash REQUIRED)
find_library(LIBRREADLINE readline REQUIRED)

add_executable(rhasher rhasher.c)
target_link_libraries(rhasher ${LIBRHASH} ${LIBRREADLINE})