cmake_minimum_required(VERSION 3.16)
project(tp_c_hw1 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_library(utils STATIC project/src/utils.c)
target_include_directories(utils PUBLIC project/include)

add_executable(tp_c_hw1 project/src/main.c)
target_link_libraries(tp_c_hw1 utils)

find_package(GTest REQUIRED)
add_executable(runTests tests/tests.cpp)
target_link_libraries(runTests GTest::gtest utils)
