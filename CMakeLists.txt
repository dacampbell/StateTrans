# Created by Duncan Campbell

# Required minimum version of CMake
cmake_minimum_required(VERSION 2.8)

# Name the project
project(StateTrans CXX)

# Set compiler flags and enable for C++11
set(CMAKE_CXX_FLAGS "-Wall -std=c++1y")

# Add in the source directory to the project build tree
add_subdirectory(src)
add_subdirectory(examples EXCLUDE_FROM_ALL)
