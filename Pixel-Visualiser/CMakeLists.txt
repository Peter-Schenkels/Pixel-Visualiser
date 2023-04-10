#header directory
set(HEADER_DIRECTORY, headers)

###############################
# Add all sources and headers #
###############################
set(HELPER_FUNCTIONS)

# create helper functions folder
source_group("Helper Functions" FILES ${HELPER_FUNCTIONS})


set(Rendering
    headers/test.hpp    
    src/test.cpp
)

# create ECS folder
source_group("Rendering" FILES ${Rendering})
###############################


# Set all sources and headers to a var
set(SRC ${Rendering})

# define the target
add_project(Pixel-Visualiser-Lib
            STATIC_LIB
            SOURCES ${SRC})

