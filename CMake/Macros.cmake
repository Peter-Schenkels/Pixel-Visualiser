macro(add_project target)
    # parse the arguments
    cmake_parse_arguments(THIS "STATIC_LIB;GUI_APP" "NAME" "SOURCES;BUNDLE_RESOURCES;DEPENDS" ${ARGN})

    # set a source group for the source files
    source_group("" FILES ${THIS_SOURCES})

    # check whether resources must be added in target
    set(target_input ${THIS_SOURCES})
    if(THIS_BUNDLE_RESOURCES)
        set(target_input ${target_input} ${THIS_BUNDLE_RESOURCES})
    endif()

    # create the target
    if(THIS_STATIC_LIB)
        add_library(${target} STATIC ${target_input})
    elseif(THIS_GUI_APP)
        add_executable(${target} ${target_input})      
    endif()

    include(${FREEGLUT_CMAKE_DIR}/FreeGLUTConfig.cmake)
    include_directories(${FREEGLUT_INCLUDE_DIR})

    # Specify the source and destination directories for the DLL files
    set(SOURCE_DLL_DIR "${FREEGLUT_DIR}/bin/$<CONFIGURATION>")
    set(DEST_DLL_DIR "${CMAKE_CURRENT_BINARY_DIR}/$<CONFIGURATION>")

    # copy freeglut.dll to specified build configuration target
    add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${FREEGLUT_DIR}/bin/$<CONFIGURATION>/freeglut$<$<CONFIG:Debug>:d>.dll"
            $<TARGET_FILE_DIR:${target}>)

    target_include_directories(${target} PRIVATE ${FREEGLUT_INCLUDE_DIR})


    if(USE_STATIC_STD_LIBS)
        set_property(TARGET ${target} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif()

    # enable precompiled headers
    if (ENABLE_PCH)
        message(VERBOSE "enabling PCH for this Project '${target}'")
        target_precompile_headers(${target} REUSE_FROM sfml-system)
    endif()

    # set the debug suffix
    set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)

    # set the target's folder (for IDEs that support it, e.g. Visual Studio)
    set_target_properties(${target} PROPERTIES FOLDER "Projects")

    # set the Visual Studio startup path for debugging
    set_target_properties(${target} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


    # link the target to its SFML dependencies
    if(THIS_DEPENDS)
        target_link_libraries(${target} PRIVATE ${THIS_DEPENDS})
    endif()

endmacro()