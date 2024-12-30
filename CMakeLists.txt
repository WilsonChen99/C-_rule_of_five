# Minimum CMake Version
cmake_minimum_required(VERSION 3.21)

# Project Name
project(MyVector)

# Requirement for C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Location of Any Include Files
include_directories(src)

# Subdirectories to build
add_subdirectory(src)
add_subdirectory(tests)

# Source File in This Directory
set(SOURCE_FILES Main.cpp)

# Create an Executable Target "main" Compiling The Source Files Tag
add_executable(main ${SOURCE_FILES})

# Link main vs the source library
target_link_libraries(main src)

