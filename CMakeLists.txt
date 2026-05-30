cmake_minimum_required(VERSION 3.20)
project(cpp_starter
    VERSION 0.1.0
    DESCRIPTION "Starter C++ project for PNT engineering"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(cpp_starter
    src/adev.cpp
)
target_include_directories(cpp_starter PUBLIC include)

enable_testing()
add_subdirectory(tests)
