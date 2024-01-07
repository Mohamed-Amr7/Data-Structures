cmake_minimum_required(VERSION 3.26)
project(stack)

set(CMAKE_CXX_STANDARD 23)

# Main executable
set(SOURCE_FILES src/stack.h src/main.cpp)
add_executable(stack ${SOURCE_FILES})

# Testing
enable_testing()

# Include directories
include_directories(src)

# Test executable
set(TEST_SOURCE_FILES tests/test_stack.cpp)
add_executable(test_stack ${TEST_SOURCE_FILES})

# Add the test
add_test(NAME stack_tests COMMAND test_stack)
