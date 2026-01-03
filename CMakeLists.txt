cmake_minimum_required(VERSION 3.10)
project(multithreaded-buffer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Required for multithreading support
find_package(Threads REQUIRED)

# Tell CMake where to find our header files
include_directories(include)

# 1. Main Demo Executable
add_executable(buffer_demo 
    src/main.cpp 
)
target_link_libraries(buffer_demo PRIVATE Threads::Threads)

# 2. Test Executable
add_executable(buffer_tests 
    tests/test_main.cpp 
    src/RingBuffer.cpp
)
target_link_libraries(buffer_tests PRIVATE Threads::Threads)