create_module_library(
    MODULE ControllerModule
    INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}
    SRCS Controller.cpp
    DEPENDS SensorModule
)
