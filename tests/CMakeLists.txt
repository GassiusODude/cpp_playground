ENABLE_TESTING()
ADD_EXECUTABLE(test_library test_library.cpp ${Playground_SOURCE_DIR}/src/math/Matrix.cpp)
ADD_TEST(NAME testlibtest COMMAND test_library)
TARGET_INCLUDE_DIRECTORIES(test_library PUBLIC ${Playground_SOURCE_DIR}/include/math)

