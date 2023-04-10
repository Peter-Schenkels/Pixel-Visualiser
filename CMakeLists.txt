cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Pixel-Visualiser VERSION 0.0.1)

include(CMake/Macros.cmake)

add_subdirectory(Pixel-Visualiser)
add_subdirectory(Examples)