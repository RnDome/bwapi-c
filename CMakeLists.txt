cmake_minimum_required(VERSION 3.2)
project(bwapi-c VERSION 0.3.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_COMPILER_IS_CLANGXX 1)
endif()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")
endif()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # To automatically create compatible .lib from .dll

if (NOT BWAPI_PATH)
    message(FATAL_ERROR "You must set BWAPI_PATH install path")
endif()

find_package(BWAPI REQUIRED)

# BWAPIC

file(GLOB_RECURSE BWAPIC_SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_library(BWAPIC SHARED ${BWAPIC_SRC})
target_include_directories(BWAPIC SYSTEM PUBLIC include/ ${BWAPI_INCLUDE_DIRS})
target_link_libraries(BWAPIC PRIVATE BWAPI BWAPIClient)

# Examples

if (MSVC)
    add_library(ExampleDll MODULE example/Dll.c)
    target_link_libraries(ExampleDll BWAPIC)

    add_executable(ExampleClient example/Client.c)
    target_link_libraries(ExampleClient BWAPIC)
endif()

# Installation

install(DIRECTORY include/ DESTINATION include)
install(TARGETS BWAPIC DESTINATION lib)

install(FILES ${BWAPI_DLL_DEBUG} DESTINATION lib CONFIGURATIONS Debug)
install(FILES ${BWAPI_DLL_RELEASE} DESTINATION lib CONFIGURATIONS Release RelWithDebInfo MinSizeRel)

# Package

set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
include(CPack)
