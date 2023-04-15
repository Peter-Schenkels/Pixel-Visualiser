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

# Math stuff
source_group("Math" FILES ${Math})

set(PixelDrawer
    src/window.cpp
    headers/window.hpp
    src/pixelVisualiser.cpp
    headers/pixelVisualiser.hpp
    src/buffer.cpp
    headers/buffer.hpp
)

# create pixel draw interface group
source_group("Interface" FILES ${PixelDrawer})


set(Tests
    src/test.cpp
    headers/test.hpp
)
# create helper functions folder
source_group("Tests" FILES ${Tests})

# Set all sources and headers to a var
set(SRC ${Tests} ${PixelDrawer} ${Math})

# define the target
add_project(Pixel-Visualiser
            STATIC_LIB
            SOURCES ${SRC}
            DEPENDS opengl32 FreeGLUT::freeglut )