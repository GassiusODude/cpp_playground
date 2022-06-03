CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(Playground
    VERSION 0.1
    DESCRIPTION "Example project with CMake"
    LANGUAGES CXX)

include(CheckLanguage)
#check_language(CUDA)
#enable_language(CUDA)

# set the C++ standard
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(apps)

IF (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    ENABLE_TESTING()
    INCLUDE(GoogleTest)
    ADD_SUBDIRECTORY(tests)
ENDIF()


# install rules
#install(TARGETS kcpp_math DESTINATION lib)
#install(FILES include/math/matrix.hpp DESTINATION include)
INSTALL(TARGETS cpp_math DESTINATION lib)
INSTALL(FILES include/math/factorial.hpp DESTINATION include/cppmath)
INSTALL(TARGETS Playground DESTINATION bin)
FIND_PACKAGE(Doxygen)
if (DOXYGEN_FOUND)
    SET(DOXYGEN_GENERATE_HTML YES)
    SET(DOXYGEN_GENERATE_MAN YES)
    doxygen_add_docs(
        doxygen
        ${Playground_SOURCE_DIR}
    )
ENDIF()