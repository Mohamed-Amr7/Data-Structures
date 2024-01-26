cmake_minimum_required(VERSION 3.26)
project(AVL)

set(CMAKE_CXX_STANDARD 23)

# Main executable
set(SOURCE_FILES src/AVL.h src/main.cpp)
add_executable(AVL ${SOURCE_FILES})

# Testing
enable_testing()

# Include directories
include_directories(src)

# Test executable
set(TEST_SOURCE_FILES tests/test_AVL.cpp)
add_executable(test_AVL ${TEST_SOURCE_FILES})

# Add the test
add_test(NAME AVL_tests COMMAND test_AVL)
