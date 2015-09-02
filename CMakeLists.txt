cmake_minimum_required(VERSION 3.3)
project(TeColor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

set(SOURCE_FILES main.cpp Spectra.cpp Spectra.h typedefs.h ColorMatchingFunction.cpp ColorMatchingFunction.h builtin_database.h EigenUtils.cpp EigenUtils.h Illuminant.cpp Illuminant.h)
add_executable(TeColor ${SOURCE_FILES})