set(HEADER_LIST "${Playground_SOURCE_DIR}/include/lib0.hpp")

add_library(lib0 SHARED lib0.cxx ${HEADER_LIST})
add_subdirectory(math)
target_include_directories(lib0 PUBLIC ../include ../include/math)
target_compile_features(lib0 PUBLIC cxx_std_11)

source_group(TREE "${Playground_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
