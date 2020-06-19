cmake_minimum_required(VERSION 3.10)

project(Playground
    VERSION 0.1
    DESCRIPTION "Example project with CMake"
    LANGUAGES CXX)

include(CheckLanguage)
#check_language(CUDA)
#enable_language(CUDA)

# set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)
add_subdirectory(apps)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
# install rules
#install(TARGETS kcpp_math DESTINATION lib)
#install(FILES include/math/matrix.hpp DESTINATION include)
install(TARGETS cpp_math DESTINATION lib)
install(FILES include/math/factorial.hpp DESTINATION include/cppmath)
