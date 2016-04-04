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

# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(ENABLE_TEST "Build all tests." OFF) # Makes boolean 'test' available.

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME MyProject)
project(${PROJECT_NAME})

if (ENABLE_TEST)
    # This adds another subdirectory, which has 'project(gtest)'.
    add_subdirectory(lib/googletest)

    enable_testing()

    # Include the gtest library. gtest_SOURCE_DIR is available due to
    # 'project(gtest)' above.
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

    add_subdirectory(test)
endif()
