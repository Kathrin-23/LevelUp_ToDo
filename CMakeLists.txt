cmake_minimum_required(VERSION 3.19) # CMAKE Requirements

project(TODO) #  Project NAME

set(CMAKE_CXX_STANDARD 20) # C++ Standard

find_package(SQLite3 REQUIRED)

if (SQLite3_NOT_FOUND)
    message(FATAL_ERROR "SQLite3 not found")
endif ()




include_directories(include) # Include Directories

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(SOURCES
    src/main.cpp
    src/commands.cpp
    src/db.cpp
    src/Helper.cpp
    )

set(HEADERS
    include/commands.hpp
    include/main.hpp
    include/db.hpp
    include/helper.hpp
    )

add_executable(TODO ${SOURCES} ${HEADERS}) # Executable

target_link_libraries(TODO sqlite3) # Link Libraries


