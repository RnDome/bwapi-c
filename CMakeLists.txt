cmake_minimum_required(VERSION 3.2)
project(bwapi)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # To automatically create compatible .lib from .dll

if (NOT BWAPI_PATH)
    message(FATAL_ERROR "You must set BWAPI_PATH install path")
endif()

find_package(BWAPI REQUIRED)
add_library(BWAPI STATIC IMPORTED)
set_property(TARGET BWAPI PROPERTY IMPORTED_LOCATION ${BWAPI_LIBRARIES})

file(GLOB_RECURSE BWAPIC_SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_library(BWAPIC SHARED ${BWAPIC_SRC})
target_include_directories(BWAPIC SYSTEM PUBLIC include/ ${BWAPI_INCLUDE_DIRS})
target_link_libraries(BWAPIC PRIVATE BWAPI)

if (MSVC)
    add_library(ExampleDLL MODULE "${CMAKE_SOURCE_DIR}/example/Dll.cpp")
    target_link_libraries(ExampleDLL BWAPIC)
endif()
