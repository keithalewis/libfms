# https://cmake.org/cmake/help/v3.13/manual/cmake-buildsystem.7.html

cmake_minimum_required(VERSION 3.10)
project(libfms VERSION 0.0.1 LANGUAGES CXX)

# Global project properties.

add_library(libfms src/template/template.cpp)
target_compile_features(libfms PRIVATE cxx_std_17)

target_include_directories(libfms
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
