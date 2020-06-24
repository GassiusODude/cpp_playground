SET(HEADER_LIST_MATH ${Playground_SOURCE_DIR}/include/math/factorial.hpp ${Playground_SOURCE_DIR}/include/math/Matrix.hpp)

ADD_LIBRARY(cpp_math SHARED factorial.cpp Matrix.cpp ${HEADER_LIST_MATH})

# specify directory for include files
TARGET_INCLUDE_DIRECTORIES(cpp_math PUBLIC ${Playground_SOURCE_DIR}/include/math)
#SOURCE_GROUP(TREE "${Playground_SOURCE_DIR}/include/math" PREFIX "Header Files" FILES ${HEADER_LIST_MATH})

TARGET_COMPILE_FEATURES(cpp_math PUBLIC cxx_std_11)
