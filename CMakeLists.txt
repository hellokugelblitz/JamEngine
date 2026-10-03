cmake_minimum_required(VERSION 3.20)
project(JamEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Detect if the user is on a linux machine.
set(LINUX_STR "Linux")
IF(CMAKE_SYSTEM_NAME STREQUAL LINUX_STR)
    SET(LINUX TRUE)
    message(STATUS "Building for: ${MY_VAR}") 
ENDIF()

IF(LINUX)
    add_executable(JamEngine
        source/main.cpp
        source/render/render.cpp
        source/input/input.cpp
        source/platform/platform.cpp
        source/platform/sdl3/platform_sdl.cpp
        vendor/glad.c
    )

    target_include_directories(JamEngine PRIVATE
        vendor
    )

   add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)

   target_link_libraries(JamEngine PRIVATE SDL3::SDL3)

ENDIF()

# TODO(jack)
IF(APPLE)

ENDIF()


# TODO(jack)
IF(WIN32)

ENDIF()



