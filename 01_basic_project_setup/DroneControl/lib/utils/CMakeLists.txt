message(STATUS "Processing lib/utils/CMakeLists.txt")
add_library(utils math_utils.cpp)
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Created utils library target")

