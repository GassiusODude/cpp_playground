set(HEADER_LIST "${Playground_SOURCE_DIR}/include/lib0.hpp")

add_library(lib0 lib0.cxx ${HEADER_LIST})

target_include_directories(lib0 PUBLIC ../include)

target_compile_features(lib0 PUBLIC cxx_std_14)

source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})