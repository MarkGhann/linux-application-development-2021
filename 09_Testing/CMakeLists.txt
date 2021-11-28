cmake_minimum_required(VERSION 3.10)

project(09_Testing)

# library
add_library(libbuffer SHARED ${CMAKE_CURRENT_SOURCE_DIR}/buf.cpp)


# tests
include(CTest)
enable_testing()
find_package(GTest REQUIRED)

add_executable(testing ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp)
target_link_libraries(testing PRIVATE ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} pthread libbuffer)

add_custom_target( tests
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/testing
    DEPENDS testing
)

add_test(
    NAME gtests
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/testing
    DEPENDS testing
)

# coverage
option(
  CODE_COVERAGE
  "Builds targets with code coverage instrumentation. (Requires GCC or Clang)"
  OFF)

if(CODE_COVERAGE)
    set(CMAKE_BUILD_TYPE Debug)
    include(${CMAKE_CURRENT_SOURCE_DIR}/code-coverage.cmake)
    target_code_coverage(testing)
endif()

add_custom_target( build_clean
        COMMAND echo "removing related files from build directory"
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/CMakeCache.txt
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/CTestTestfile.cmake
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/DartConfiguration.tcl
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/Testing
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/ccov
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/Makefile
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/cmake_install.cmake
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/liblibbuffer.so
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/testing
        COMMAND echo "build directory cleaned"
)