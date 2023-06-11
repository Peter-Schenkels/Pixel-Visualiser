#header directory
set(HEADER_DIRECTORY, headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Pixel-Visualiser)


###############################
# Add all sources and headers #
###############################
set(HELPER_FUNCTIONS)

# create helper functions folder
source_group("Helper Functions" FILES ${HELPER_FUNCTIONS})

set(Math
    headers/vector2.hpp
    headers/vector3.hpp
)

source_group("Math" FILES ${Math})

set(Input
	headers/mouse.hpp
	src/mouse.cpp
	headers/keyboard.hpp
	src/keyboard.cpp
)


source_group("Input" FILES ${Input})

set(PixelDrawer
    headers/window.hpp
    src/window.cpp
	headers/buffer.hpp
    src/buffer.cpp
	headers/pixelVisualiser.hpp
    src/pixelVisualiser.cpp
)

# create pixel draw interface group
source_group("Interface" FILES ${PixelDrawer})


# Set all sources and headers to a var
set(SRC ${Tests} ${Input} ${PixelDrawer} ${Math})

# define the target
add_project(Pixel-Visualiser
            STATIC_LIB
            SOURCES ${SRC}
            DEPENDS opengl32 FreeGLUT::freeglut )