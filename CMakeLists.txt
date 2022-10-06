cmake_minimum_required(VERSION 3.19) # CMAKE Requirements

project(TODO) #  Project NAME

set(CMAKE_CXX_STANDARD 20) # C++ Standard

include_directories(include) # Include Directories

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(SOURCES
    src/main.cpp
    src/commands.cpp
    )

add_executable(TODO ${SOURCES}) # Executable


