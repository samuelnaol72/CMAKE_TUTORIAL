function(create_module_library)
    set(options)
    set(oneValueArgs MODULE)
    set(multiValueArgs SRCS INCLUDES DEPENDS)
    set(requiredArgs MODULE SRCS)

    cmake_parse_arguments(PARSE "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Validate required arguments
    foreach(req_arg ${requiredArgs})
        if(NOT PARSE_${req_arg})
            message(FATAL_ERROR "Missing required argument: ${req_arg}")
        endif()
    endforeach()

    # Create static library
    add_library(${PARSE_MODULE} STATIC ${PARSE_SRCS})

    # Add include directories if provided
    if(PARSE_INCLUDES)
        target_include_directories(${PARSE_MODULE} PUBLIC ${PARSE_INCLUDES})
    endif()

    # Link dependencies if provided
    if(PARSE_DEPENDS)
        target_link_libraries(${PARSE_MODULE} PUBLIC ${PARSE_DEPENDS})
    endif()

    # Show status
    message(STATUS "Created library: ${PARSE_MODULE}")
    message(STATUS "  Sources: ${PARSE_SRCS}")
    if(PARSE_INCLUDES)
        message(STATUS "  Includes: ${PARSE_INCLUDES}")
    endif()
    if(PARSE_DEPENDS)
        message(STATUS "  Depends on: ${PARSE_DEPENDS}")
    endif()
endfunction()

