add_executable(Playground playground.cxx)
target_compile_features(Playground PUBLIC cxx_std_11)

# NOTE: This is for use with ZMQ on Linux
#       Resolves to nothing in Windows
find_package(Threads REQUIRED)
target_link_libraries(Playground PRIVATE Threads::Threads)

#
# Find packages via vcpkg (or any CMake config package)
# These provide IMPORTED targets:
#   cppzmq
#   ZeroMQ::libzmq
#
find_package(cppzmq REQUIRED)
find_package(ZeroMQ REQUIRED)

#
# Check which variant we got: CONFIG or MODULE
#
# CONFIG (vcpkg, Conan, Windows):
#   → creates imported target ZeroMQ::libzmq
#
# MODULE (Linux default FindZeroMQ.cmake):
#   → gives variables: ZeroMQ_LIBRARY, ZeroMQ_INCLUDE_DIR
#
if(TARGET ZeroMQ::libzmq)
    message(STATUS "Using imported target ZeroMQ::libzmq")
    target_link_libraries(Playground PRIVATE cppzmq ZeroMQ::libzmq)

elseif(ZeroMQ_LIBRARY)
    # Fix for vcpkg MODULE mode incorrectly returning DLL instead of LIB
    if(ZeroMQ_LIBRARY MATCHES "\\.dll$")
        message(STATUS "Correcting ZeroMQ library path from DLL to LIB...")
        get_filename_component(_zmq_dir "${ZeroMQ_LIBRARY}" DIRECTORY)
        # go from bin → lib
        string(REPLACE "/bin" "/lib" _zmq_libdir "${_zmq_dir}")
        # guess the correct .lib name
        file(GLOB _zmq_lib "${_zmq_libdir}/libzmq*.lib")
        if(_zmq_lib)
            set(ZeroMQ_LIBRARY "${_zmq_lib}")
            message(STATUS "ZeroMQ_LIBRARY corrected to: ${ZeroMQ_LIBRARY}")
        else()
            message(FATAL_ERROR "Unable to locate libzmq .lib import library in ${_zmq_libdir}")
        endif()
    endif()


    message(STATUS "Using variable-based ZeroMQ library: ${ZeroMQ_LIBRARY}")
    target_include_directories(Playground PRIVATE ${ZeroMQ_INCLUDE_DIR})
    target_link_libraries(Playground PRIVATE cppzmq ${ZeroMQ_LIBRARY})

else()
    message(FATAL_ERROR "ZeroMQ was found but no usable target or library was detected.")
endif()

#
# Optional: pkg-config fallback for Linux/MSYS2
#
if(UNIX AND NOT WIN32 AND NOT TARGET ZeroMQ::libzmq AND NOT ZeroMQ_LIBRARY)
    find_package(PkgConfig QUIET)
    if(PkgConfig_FOUND)
        pkg_check_modules(PC_ZeroMQ QUIET libzmq)
        if(PC_ZeroMQ_FOUND)
            message(STATUS "Using pkg-config ZeroMQ")
            target_include_directories(Playground PRIVATE ${PC_ZeroMQ_INCLUDE_DIRS})
            target_link_libraries(Playground PRIVATE ${PC_ZeroMQ_LIBRARIES})
        endif()
    endif()
endif()

#
# Windows note
#
if(WIN32)
    message(STATUS "Ensure libzmq DLL is present on PATH or next to the executable.")
endif()