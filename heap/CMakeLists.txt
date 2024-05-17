cmake_minimum_required(VERSION 3.26)
project(heap)

set(CMAKE_CXX_STANDARD 23)

# Main executable
set(SOURCE_FILES src/heap.h src/main.cpp)
add_executable(heap ${SOURCE_FILES})

# Testing
enable_testing()

# Include directories
include_directories(src)

# Test executable
set(TEST_SOURCE_FILES tests/test_heap.cpp)
add_executable(test_heap ${TEST_SOURCE_FILES})

# Add the test
add_test(NAME heap_tests COMMAND test_heap)
