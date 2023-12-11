cmake_minimum_required(VERSION 3.26)
project(binary_search_tree)

set(CMAKE_CXX_STANDARD 23)

# Main executable
set(SOURCE_FILES src/binary_search_tree.h src/main.cpp)
add_executable(binary_search_tree ${SOURCE_FILES})

# Testing
enable_testing()

# Include directories
include_directories(src)

# Test executable
set(TEST_SOURCE_FILES tests/test_binary_search_tree.cpp)
add_executable(test_binary_search_tree ${TEST_SOURCE_FILES})

# Add the test
add_test(NAME binary_search_tree_tests COMMAND test_binary_search_tree)
