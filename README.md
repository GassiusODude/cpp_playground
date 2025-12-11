# CPP Playground
This is a testing ground for me to practice
* Setting up a cmake project
* Implementing functions/classes in C++

## Prerequisites
* cmake > 3.10

## Installation
~~~
cd build
cmake -DBUILD_TESTING=ON .. && make
sudo make install
~~~

### Windows

~~~bash
    # Instal vcpkg to get zeromq and cppzmq
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
cd build
./tests/test_library
~~~