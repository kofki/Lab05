cmake_minimum_required(VERSION 3.29)
project(Lab05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab05
    analyzer.cpp
    StringData.h)
