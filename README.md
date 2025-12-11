# CPP Playground

This is a testing ground for me to practice

* Setting up a cmake project
* Implementing functions/classes in C++

| Function | Tests | Status | Description |
| :-: | :-: | :-: | :-: |
| app/Playground | - | Initial | Set up ZMQ publisher/subscriber |
| src/math/factorial.cpp | - | Implemented | Recursive implementation |
| src/math/frequency.cpp | - | Implemented | Frequency shift |
| src/math/matrix.cpp | [tests/test_matrix.cpp](./tests/test_matrix.cpp) | Implemented | Implemented and tested (add, determininant)

## Prerequisites

* cmake > 3.15

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

### Windows

~~~bash
    # Install vcpkg to get zeromq and cppzmq
    git clone https://github.com/microsoft/vcpkg
    vcpkg/bootstrap-vcpkg.sh -disableMetrics
    vcpkg/vcpkg.exe install zeromq:x64-windows cppzmq:x64-windows

    # cmake and build
    cmake -S . -B build  -DCMAKE_TOOLCHAIN_FILE="C:\Path\To\vcpkg\scripts\buildsystems\vcpkg.cmake"
    cmake --build build
~~~

## Test

This assumes that cmake was provided with "-DBUILD_TESTING=ON"

~~~bash
    # On Linux
    cd build
    ./tests/test_library

    # On windows
    .\build\tests\Debug\test_library.exe
~~~