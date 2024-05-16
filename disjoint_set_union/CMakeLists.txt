cmake_minimum_required(VERSION 3.26)
project(disjoint_set_union)

set(CMAKE_CXX_STANDARD 23)

# Main executable
set(SOURCE_FILES src/disjoint_set_union.h src/main.cpp)
add_executable(disjoint_set_union ${SOURCE_FILES})

# Testing
enable_testing()

# Include directories
include_directories(src)

# Test executable
set(TEST_SOURCE_FILES tests/test_disjoint_set_union.cpp)
add_executable(test_disjoint_set_union ${TEST_SOURCE_FILES})

# Add the test
add_test(NAME disjoint_set_tests COMMAND test_disjoint_set_union)
