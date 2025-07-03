cmake_minimum_required(VERSION 3.14)
project(CMAKE_TUTORIAL2)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(create_module_library)
add_subdirectory(SensorModule)
add_subdirectory(ControllerModule)
