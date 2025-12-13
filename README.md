# CPP Playground

[TOC]

This is a testing ground for me to practice

* Setting up a cmake project
* Implementing functions/classes in C++

| Function | Tests | Status | Description |
| :-: | :-: | :-: | :-: |
| app/Playground | - | Initial | Set up ZMQ publisher/subscriber |
| src/math/factorial.cpp | [tests/test_factorial.cpp](./tests/test_factorial.cpp) | Implemented | Recursive implementation |
| src/math/frequency.cpp | - | Implemented | Frequency shift |
| src/math/matrix.cpp | [tests/test_matrix.cpp](./tests/test_matrix.cpp) | Implemented | Implemented and tested (add, determininant)

## Prerequisites

* cmake > 3.15
* libzmq + cppzmq

## Installation

GTest is pulled as a submodule to support testing.  

~~~bash
    # Pull the GTest Submodule
    git submodule init
    git submodule update

    # build and install
    cd build
    cmake -DBUILD_TESTING=ON .. && make
    sudo make install
~~~

### Linux

On Ubuntu, some dependencies are expected.  CMake currently not set up to install it if not found.

~~~bash
    # NOTE: Ubuntu specifically
    # =====================================================
    # install libzmq
    sudo apt install libzmq3-dev
      
    # install cppzmq
    git clone https://github.com/zeromq/cppzmq.git
    cd cppzmq
    cmake -B build
    cmake --build build
    sudo cmake --install build
~~~

Next, build the project

~~~bash
    # Install CPP Playground
    # =====================================================
    cd cpp_playground

    # NOTE: build with testing
    cmake -B build -S . -DBUILD_TESTING=ON
    cmake --build build
~~~

### Windows

On Windows, I tested by installing the dependencies through `vcpkg`.

~~~bash
    # Install vcpkg to get zeromq and cppzmq
    git clone https://github.com/microsoft/vcpkg
    vcpkg/bootstrap-vcpkg.sh -disableMetrics
    vcpkg/vcpkg.exe install zeromq:x64-windows cppzmq:x64-windows
~~~

Then to build the project, the `-DCAME_TOOLCHAIN_FILE` is specified.

~~~bash
    # cmake and build
    cmake -S . -B build  -DCMAKE_TOOLCHAIN_FILE="C:\Path\To\vcpkg\scripts\buildsystems\vcpkg.cmake"
    cmake --build build
~~~

## Test

This assumes that CMake built with `-DBUILD_TESTING=ON` option activated.

~~~bash
    # On Linux
    /build/tests/test_library

    # On windows
    .\build\tests\Debug\test_library.exe
~~~