cmake_minimum_required(VERSION 3.5)
project(bwapi)

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

file(GLOB_RECURSE BWAPIC_SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_library(BWAPIC ${BWAPIC_SRC})
target_include_directories(BWAPIC SYSTEM PUBLIC include/)
target_include_directories(BWAPIC SYSTEM PRIVATE "~/Downloads/BWAPI/include") # TODO
