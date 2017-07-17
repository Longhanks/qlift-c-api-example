# Define minimum cmake version
cmake_minimum_required(VERSION 2.8.11)

# Define project name
project(qlift-c-api-example)

# Define version number
set(VERSION "0.0.1")

# Define include dir
include_directories(
    ${CMAKE_SOURCE_DIR}/lib/qlift-c-api/src/public
    ${CMAKE_SOURCE_DIR}/lib/qlift-c-api/src
)

set(ENABLE_SHARED OFF CACHE BOOL "Do not build shared library")
set(ENABLE_STATIC ON CACHE BOOL "Build static library")
add_subdirectory(lib/qlift-c-api)

# Define source files
set(SOURCES
    src/main.c
)

# Binary output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Define binary target
add_executable(qlift-c-api-example ${SOURCES})

# Define linked libs
target_link_libraries(qlift-c-api-example qlift-c-api)

