#header directory
set(HEADER_DIRECTORY, headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Pixel-Visualiser)


###############################
# Add all sources and headers #
###############################
set(HELPER_FUNCTIONS)

# create helper functions folder
source_group("Helper Functions" FILES ${HELPER_FUNCTIONS})

set(Tests
    src/main.cpp
)
# create helper functions folder
source_group("Tests" FILES ${Tests})

# Set all sources and headers to a var
set(SRC ${Tests})

# define the target
add_project(Test
            GUI_APP
            SOURCES ${SRC}
            DEPENDS Pixel-Visualiser-Lib)

