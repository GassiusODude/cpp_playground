ENABLE_TESTING()
ADD_SUBDIRECTORY("${Playground_SOURCE_DIR}/extern/googletest" "extern/googletest")
ADD_EXECUTABLE(test_library 
    test_matrix.cpp 
    test_factorial.cpp
    ${Playground_SOURCE_DIR}/src/math/matrix.cpp
    ${Playground_SOURCE_DIR}/src/math/factorial.cpp)
TARGET_LINK_LIBRARIES(test_library gtest gmock gtest_main)
ADD_TEST(NAME testlibtest COMMAND test_library)
TARGET_INCLUDE_DIRECTORIES(test_library PUBLIC ${Playground_SOURCE_DIR}/include/math)

