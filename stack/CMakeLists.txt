cmake_minimum_required(VERSION 3.26)
project(queue)

set(CMAKE_CXX_STANDARD 23)

# Main executable
set(SOURCE_FILES src/stack.h src/main.cpp)
add_executable(queue ${SOURCE_FILES})

# Testing
enable_testing()

# Include directories
include_directories(src)

# Test executable
set(TEST_SOURCE_FILES tests/test_stack.cpp)
add_executable(test_queue ${TEST_SOURCE_FILES})

# Add the test
add_test(NAME queue_tests COMMAND test_queue)
