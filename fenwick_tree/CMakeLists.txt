cmake_minimum_required(VERSION 3.26)
project(fenwick_tree)

set(CMAKE_CXX_STANDARD 23)

# Main executable
set(SOURCE_FILES src/fenwick_tree.h src/main.cpp)
add_executable(stack ${SOURCE_FILES})

# Testing
enable_testing()

# Include directories
include_directories(src)

# Test executable
set(TEST_SOURCE_FILES tests/test_fenwick_tree.cpp)
add_executable(test_fenwick_tree ${TEST_SOURCE_FILES})

# Add the test
add_test(NAME fenwick_tree_tests COMMAND test_fenwick_tree)
