cmake_minimum_required(VERSION 3.3)
project(TeColor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})


set(TECOLOR_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

include_directories(${TECOLOR_INCLUDE_DIR})
add_subdirectory(src/tecolor)
add_subdirectory(demo)

