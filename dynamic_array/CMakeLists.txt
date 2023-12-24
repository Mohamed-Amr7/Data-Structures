cmake_minimum_required(VERSION 3.26)
project(dynamic_array)

set(CMAKE_CXX_STANDARD 23)

# Main executable
set(SOURCE_FILES src/dynamic_array.h src/main.cpp)
add_executable(dynamic_array ${SOURCE_FILES})

# Testing
enable_testing()

# Include directories
include_directories(src)

# Test executable
set(TEST_SOURCE_FILES tests/test_dynamic_array.cpp)
add_executable(test_dynamic_array ${TEST_SOURCE_FILES})

# Add the test
add_test(NAME dynamic_array_tests COMMAND test_dynamic_array)
