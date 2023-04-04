# The CMake List File for the library

cmake_minimum_required(VERSION 3.14)

project(SimpleTestFramework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_library(simple_test_framework STATIC src/TestLight.cpp)