cmake_minimum_required (VERSION 2.8)
set(CMAKE_CXX_COMPILER "/usr/bin/x86_64-redhat-linux-g++")
set (CMAKE_CXX_STANDARD 17)
PROJECT(Game CXX)

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_subdirectory(src)