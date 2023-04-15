cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(FREEGLUT_DIR "Default" CACHE STRING "Helpstring")
set(FREEGLUT_INCLUDE_DIR "Default" CACHE STRING "Helpstring")

SET(FREEGLUT_CMAKE_DIR ${FREEGLUT_DIR}/FreeGLUT)


project(Pixel-Visualiser VERSION 0.0.1)

include(CMake/Macros.cmake)

add_subdirectory(Pixel-Visualiser)
add_subdirectory(Examples)