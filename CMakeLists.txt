cmake_minimum_required(VERSION 3.10)

project(Playground
    VERSION 0.1
    DESCRIPTION "Example project with CMake"
    LANGUAGES CXX)

# set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)
add_subdirectory(apps)
