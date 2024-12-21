cmake_minimum_required(VERSION 3.30)
project(rustls-ffi-test C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(RUSTLS REQUIRED rustls=0.15.0)

message(STATUS "RUSTLS_INCLUDE_DIRS: ${RUSTLS_INCLUDE_DIRS}")
message(STATUS "RUSTLS_LIBRARY_DIRS: ${RUSTLS_LIBRARY_DIRS}")
message(STATUS "RUSTLS_LIBRARIES: ${RUSTLS_LIBRARIES}")

add_executable(rustls-ffi-test main.c)
target_link_libraries(rustls-ffi-test PRIVATE ${RUSTLS_LIBRARIES})
target_include_directories(rustls-ffi-test PRIVATE ${RUSTLS_INCLUDE_DIRS})
target_link_directories(rustls-ffi-test PRIVATE ${RUSTLS_LIBRARY_DIRS})

if(WIN32)
    target_link_libraries(
            rustls-ffi-test
            PRIVATE
            advapi32.lib
            bcrypt.lib
            crypt32.lib
            cryptnet.lib
            kernel32.lib
            ncrypt.lib
            bcrypt.lib
            advapi32.lib
            legacy_stdio_definitions.lib
            kernel32.lib
            advapi32.lib
            kernel32.lib
            ntdll.lib
            userenv.lib
            ws2_32.lib
            synchronization.lib
            kernel32.lib
            ws2_32.lib
            kernel32.lib
            msvcrt.lib
    )
    set_property(
            TARGET rustls-ffi-test
            PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDLL"
    )
endif()
