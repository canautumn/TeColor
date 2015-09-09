cmake_minimum_required(VERSION 3.3)
project(TeColor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_library(tecolor Spectra.cpp ColorMatchingFunction.cpp EigenUtils.cpp Illuminant.cpp Primaries.cpp Tristimulus.cpp SpectralKit.cpp ReflectanceSet.cpp CIELAB.cpp)


set(SOURCE_FILES main.cpp)
add_executable(tecolor_demo ${SOURCE_FILES})
target_link_libraries(tecolor_demo tecolor)

