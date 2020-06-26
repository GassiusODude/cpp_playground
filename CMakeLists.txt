CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(Playground
    VERSION 0.1
    DESCRIPTION "Example project with CMake"
    LANGUAGES CXX)

include(CheckLanguage)
#check_language(CUDA)
#enable_language(CUDA)
include(CTest)

# set the C++ standard
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(apps)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    ADD_SUBDIRECTORY(tests)
endif()

# install rules
#install(TARGETS kcpp_math DESTINATION lib)
#install(FILES include/math/matrix.hpp DESTINATION include)
install(TARGETS cpp_math DESTINATION lib)
install(FILES include/math/factorial.hpp DESTINATION include/cppmath)
