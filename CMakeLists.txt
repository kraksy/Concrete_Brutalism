cmake_minimum_required(VERSION 3.10)
project(Concrete_Brutalism VERSION 0.1)

cmake_policy(SET CMP0135 NEW)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/main.cpp
    src/comp/Input.cpp
    src/comp/Input.h
    src/comp/Render.cpp
    src/comp/Render.h
    src/entities/Player.h
    src/utils/Utils.cpp
    src/utils/Utils.h
    src/Game.cpp
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

add_executable(Concrete_Brutalism ${SOURCES})

target_link_libraries(Concrete_Brutalism PRIVATE raylib)
