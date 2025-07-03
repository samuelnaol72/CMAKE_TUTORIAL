# 🚀 01_basic_project_setup — CMake Tutorial

This module demonstrates how to set up a basic C++ project using **CMake**, focusing on:

- Organizing source, headers, and libraries
- Creating and linking a static library
- Setting compile options and macros
- Understanding `PRIVATE`, `PUBLIC`, and `INTERFACE` usage

---

## 📁 Project Structure

```
DroneControl/
├── CMakeLists.txt
├── include/
│   └── drone.h
├── src/
│   ├── main.cpp
│   └── drone.cpp
├── lib/
│   └── utils/
│       ├── math_utils.cpp
│       ├── math_utils.h
│       └── CMakeLists.txt
└── build/
```

---

## ⚙️ Build Instructions

```bash
mkdir build
cd build
cmake ..
make
./drone_app
```

To disable logging:

```bash
cmake .. -DUSE_LOGGING=OFF
```

---

## 🔧 CMake Highlights

### 1. Creating Targets

```cmake
add_library(utils math_utils.cpp)
add_executable(drone_app src/main.cpp src/drone.cpp)
```

Creates a static library `utils` and an executable `drone_app`.

---

### 2. Including Directories

```cmake
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(drone_app PRIVATE include)
```

- `PUBLIC`: used by this target **and** exposed to targets that link it.
- `PRIVATE`: used **only** by this target.

---

### 3. Linking Targets

```cmake
target_link_libraries(drone_app PRIVATE utils)
```

Links `drone_app` to the `utils` library.

---

### 4. Adding Compile-Time Options

```cmake
option(USE_LOGGING "Enable logging" ON)

if(USE_LOGGING)
    target_compile_definitions(drone_app PRIVATE ENABLE_LOGGING=1)
endif()
```

Adds a preprocessor macro when logging is enabled.

---

## 📚 Key Takeaways

- `PRIVATE`: For internal use — doesn’t affect other targets.
- `PUBLIC`: Affects both the current and dependent targets.
- `INTERFACE`: Used only by dependents — useful for header-only libraries.

> 📌 Only expose what is necessary to use a target — not how to build it.

---

Happy building! 🛠

