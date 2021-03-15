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

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/code_coverage/cmake_modules)
if (CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    append_coverage_compiler_flags()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")

    setup_target_for_coverage_lcov(
            NAME code_covr_lconv
            EXECUTABLE runTests
            DEPENDENCIES runTests utils
    )
    setup_target_for_coverage_gcovr_html(
            NAME code_covr_gcovr_html
            EXECUTABLE runTests
            DEPENDENCIES runTests utils
    )
endif ()