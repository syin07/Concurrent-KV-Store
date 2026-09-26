cmake_minimum_required(VERSION 3.25)

project(ConcurrentKV LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)          # -std=c++20, not -std=gnu++20
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # compile_commands.json for editor tooling

# Warnings for our own targets only (not third-party code like GoogleTest).
add_library(kv_warnings INTERFACE)
target_compile_options(kv_warnings INTERFACE -Wall -Wextra -Wpedantic -Wshadow -Wconversion)

# The store itself. Server, tests, and benchmarks all link against this.
add_library(kvstore
    src/version.cpp
)
target_include_directories(kvstore PUBLIC include)
target_link_libraries(kvstore PRIVATE kv_warnings)

# Server executable (hello world for now).
add_executable(kvserver src/main.cpp)
target_link_libraries(kvserver PRIVATE kvstore kv_warnings)

# Tests
include(CTest)  # defines BUILD_TESTING (ON by default) and calls enable_testing()
if(BUILD_TESTING)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.tar.gz
        SYSTEM  # treat its headers as system headers: no warnings from code we don't own
    )
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_subdirectory(tests)
endif()
