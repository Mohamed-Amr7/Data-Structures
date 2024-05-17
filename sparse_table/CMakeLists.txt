cmake_minimum_required(VERSION 3.26)
project(sparse_table)

set(CMAKE_CXX_STANDARD 23)

# Main executable
set(SOURCE_FILES src/sparse_table.h src/main.cpp)
add_executable(stack ${SOURCE_FILES})

# Testing
enable_testing()

# Include directories
include_directories(src)

# Test executable
set(TEST_SOURCE_FILES tests/test_sparse_table.cpp)
add_executable(test_sparse_table ${TEST_SOURCE_FILES})

# Add the test
add_test(NAME sparse_table_tests COMMAND test_sparse_table)
