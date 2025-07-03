cmake_minimum_required(VERSION 3.16)
project(DroneControl VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Adding subdirectory lib/utils...")
add_subdirectory(lib/utils)

message(STATUS "Creating executable drone_app...")
add_executable(drone_app src/main.cpp src/drone.cpp)
target_include_directories(drone_app PRIVATE include)
target_link_libraries(drone_app PRIVATE utils)
message(STATUS "Created drone_app target")

option(USE_LOGGING "Enable logging" ON)
if(USE_LOGGING)
    target_compile_definitions(drone_app PRIVATE ENABLE_LOGGING=1)
endif()

