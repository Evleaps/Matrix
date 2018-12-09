# cmake_minimum_required(VERSION <specify CMake version here>)
project(matrix)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp matrix.cpp matrix.h tests/tests_of_class.cpp tests/tests_of_class.h tests/test_of_extension.cpp tests/test_of_extension.h)

add_executable(matrix ${SOURCE_FILES})