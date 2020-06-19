set(HEADER_LIST_MATH "${Playground_SOURCE_DIR}/include/math/factorial.hpp")

add_library(cpp_math SHARED factorial.cxx Matrix.cxx ${HEADER_LIST_MATH})

# specify directory for include files
target_include_directories(cpp_math PUBLIC ${Playground_SOURCE_DIR}/include/math)
source_group(TREE "${Playground_SOURCE_DIR}/include/math" PREFIX "Header Files" FILES ${HEADER_LIST_MATH})

target_compile_features(cpp_math PUBLIC cxx_std_11)
