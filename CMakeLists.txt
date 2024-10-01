cmake_minimum_required(VERSION 3.10)
project(smolgame VERSION 0.1)

cmake_policy(SET CMP0135 NEW)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/Camera.cpp
    src/Camera.h
    src/Core.cpp
    src/Core.h
    src/ErrorHandle.cpp
    src/ErrorHandle.h
    src/Game.cpp
    src/Game.h
    src/InputHandle.cpp
    src/InputHandle.h
    src/MemoryHandle.cpp
    src/MemoryHandle.h
    src/ModelLoad.cpp
    src/ModelLoad.h
    src/Player.cpp
    src/Player.h
    src/Render.cpp
    src/Render.h
    src/Shaders.cpp
    src/Shaders.h
    src/main.cpp
)

include(FetchContent)

set(RAYLIB_VERSION 5.0)
FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
        FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(raylib)

add_executable(smolgame ${SOURCES})

target_link_libraries(smolgame PRIVATE raylib)
