#header directory
set(HEADER_DIRECTORY, headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Pixel-Visualiser)


###############################
# Add all sources and headers #
###############################
set(src
    src/main.cpp
	CMakeLists.txt
)
# create helper functions folder
source_group("Colored Squares" FILES ${src})

# Set all sources and headers to a var
set(SRC ${src})

# define the target
add_project(
			Colored-Squares
			EXAMPLE
            SOURCES ${SRC}
            DEPENDS Pixel-Visualiser opengl32 FreeGLUT::freeglut )
