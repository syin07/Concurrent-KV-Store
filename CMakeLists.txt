cmake_minimum_required(VERSION 4.4.3)

project(ConcurrentKV)

add_executable(main)
target_sources(main
    PRIVATE
        src/main.cpp
)