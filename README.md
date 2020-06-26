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

## Test
This assumes that cmake was provided with "-DBUILD_TESTING=ON"

~~~bash
cd build
./tests/test_library
~~~