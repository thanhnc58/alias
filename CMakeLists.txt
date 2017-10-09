cmake_minimum_required(VERSION 3.8)
project(Alias_table)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp xorshift.h xorshift.cpp)
add_executable(Alias_table ${SOURCE_FILES})