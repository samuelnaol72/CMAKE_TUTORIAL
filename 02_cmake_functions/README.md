# CMake Tutorial - 02: Custom CMake Functions

This project provides a practical example of creating custom CMake functions to enable modular, reusable, and declarative build configurations, inspired by PX4's module system.

## 📁 Project Structure

```
02_cmake_functions/
├── build/                    # Build output directory
├── cmake/                    # Custom CMake functions
│   ├── create_module_library.cmake
│   └── parse_function_args.cmake
├── SensorModule/             # Independent sensor module
│   ├── Sensor.cpp
│   ├── Sensor.hpp
│   └── CMakeLists.txt
├── ControllerModule/         # Module dependent on SensorModule
│   ├── Controller.cpp
│   ├── Controller.hpp
│   └── CMakeLists.txt
├── CMakeLists.txt            # Top-level CMake configuration
```

## 🔧 Custom Function: `create_module_library`

Defined in `cmake/create_module_library.cmake`, this function simplifies module creation by wrapping:

- `add_library`
- `target_include_directories`
- `target_link_libraries` (for optional `DEPENDS`)

### ✅ Example Usage

In a module's `CMakeLists.txt`:

```cmake
# SensorModule
create_module_library(
    MODULE SensorModule
    INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}
    SRCS Sensor.cpp
)

# ControllerModule (depends on SensorModule)
create_module_library(
    MODULE ControllerModule
    INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}
    SRCS Controller.cpp
    DEPENDS SensorModule
)
```

## 🧪 How to Build

From the project root:

```bash
mkdir -p build
cd build
cmake ..
make
```

Expected output:

```
[ 50%] Built target SensorModule
[100%] Built target ControllerModule
```

## ✅ Learning Objectives

- Parse custom function arguments with `cmake_parse_arguments`.
- Create a reusable `create_module_library` function for modular builds.
- Manage inter-module dependencies cleanly.

## 📚 References

- [CMake `cmake_parse_arguments` Documentation](https://cmake.org/cmake/help/latest/command/cmake_parse_arguments.html)
- PX4 `px4_add_module` Design

## 📝 Prerequisites

- CMake 3.10 or higher
- A C++ compiler (e.g., GCC, Clang)

## 🚀 Getting Started

Clone the repository and follow the build instructions to explore custom CMake functions and modular build setups!
