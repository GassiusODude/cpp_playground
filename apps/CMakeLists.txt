add_executable(Playground playground.cxx)
target_compile_features(Playground PUBLIC cxx_std_11)

find_package(PkgConfig)
pkg_check_modules(PC_ZeroMQ QUIET zmq)
find_path(ZeroMQ_INCLUDE_DIR
    NAMES zmq.hpp
    PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
)
find_library(ZeroMQ_LIBRARY
    NAMES zmq
    PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
)
target_include_directories(Playground PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(Playground PUBLIC ${ZeroMQ_LIBRARY})