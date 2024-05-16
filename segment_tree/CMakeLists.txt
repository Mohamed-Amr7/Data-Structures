cmake_minimum_required(VERSION 3.26)
project(segment_tree)

set(CMAKE_CXX_STANDARD 23)

# Main executable
set(SOURCE_FILES src/segment_tree.h src/main.cpp)
add_executable(segment_tree ${SOURCE_FILES})

# Testing
enable_testing()

# Include directories
include_directories(src)

# Test executable
set(TEST_SOURCE_FILES tests/test_segment_tree.cpp)
add_executable(test_segment_tree ${TEST_SOURCE_FILES})

# Add the test
add_test(NAME segment_tree_tests COMMAND test_segment_tree)
