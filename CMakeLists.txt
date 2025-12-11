cmake_minimum_required(VERSION 3.15)

project(Playground
    VERSION 0.1
    DESCRIPTION "Example project with CMake"
    LANGUAGES CXX
)

# Prefer CONFIG packages (required for vcpkg)
set(CMAKE_FIND_PACKAGE_PREFER_CONFIG TRUE)

# ------------------------------
# C++ Standard (portable)
# ------------------------------
# This works for MSVC, GCC, and Clang — no manual flags needed
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Do NOT add manual flags like -std=c++11 or -pthread.  
# CMake chooses correct flags based on compiler.

# ------------------------------
# Subdirectories
# ------------------------------
add_subdirectory(src)
add_subdirectory(apps)

# ------------------------------
# Optional Unit Tests
# ------------------------------
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()

# ------------------------------
# Install Rules
# ------------------------------
install(TARGETS cpp_math DESTINATION lib)
install(FILES include/math/factorial.hpp DESTINATION include/cppmath)
install(TARGETS Playground DESTINATION bin)

# ------------------------------
# Doxygen (optional)
# ------------------------------
find_package(Doxygen QUIET)
if (DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_MAN YES)

    doxygen_add_docs(
        doxygen
        ${Playground_SOURCE_DIR}
    )
endif()
