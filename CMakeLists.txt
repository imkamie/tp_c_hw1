cmake_minimum_required(VERSION 3.16)
project(tp_c_hw1 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wpedantic -Werror --coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Werror --coverage")

add_library(utils STATIC project/src/utils.c)
target_include_directories(utils PUBLIC project/include)

add_executable(tp_c_hw1 project/src/main.c)
target_link_libraries(tp_c_hw1 utils)

find_package(GTest REQUIRED)
set(SOURCES tests/run_tests.cpp tests/test_allocation.cpp tests/test_print.cpp tests/test_push.cpp tests/test_resize.cpp tests/test_sort.cpp tests/test_values.cpp)
add_executable(runTests ${SOURCES})
target_link_libraries(runTests GTest::gtest utils)
