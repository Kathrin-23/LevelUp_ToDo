cmake_minimum_required(VERSION 3.23) # CMAKE Requirements

project(TODO) #  Project NAME

set(CMAKE_CXX_STANDARD 20) # C++ Standard

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall")

#find_package(SQLite3 REQUIRED)
#
#if (SQLite3_NOT_FOUND)     #Закоментируй этот блок!
#    message(FATAL_ERROR "SQLite3 not found")
#endif ()

#if(WIN32)
#    set(CMAKE_PREFIX_PATH C:\\sqlite)     !!!!! Установи свой путь до sqlite
#endif()
#
#find_package(SQLite3 REQUIRED)

include(FetchContent)

FetchContent_Declare(sqlite URL https://github.com/fnc12/sqlite_orm/archive/refs/heads/master.zip)
FetchContent_MakeAvailable(sqlite)


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

target_include_directories(TODO PRIVATE ${SQLite3_INCLUDE_DIRS})
#target_link_libraries(TODO ${SQLite3_LIBRARIES})

target_link_libraries(TODO sqlite3)


