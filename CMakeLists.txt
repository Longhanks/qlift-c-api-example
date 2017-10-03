# Define minimum cmake version
cmake_minimum_required(VERSION 3.0.0)

if(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9" CACHE STRING "Minimum OS X deployment version")
endif()

# Define project name
project(qlift-c-api-example)

# Define version number
set(VERSION "0.0.1")

# output compile database (useful for completion)
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

# Define include dir
include_directories(
    ${CMAKE_SOURCE_DIR}/lib/qlift-c-api/src/public
    ${CMAKE_SOURCE_DIR}/lib/qlift-c-api/src
)

# Add qlift-c-api
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

