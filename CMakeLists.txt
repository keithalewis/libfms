# https://cmake.org/cmake/help/v3.13/manual/cmake-buildsystem.7.html

cmake_minimum_required(VERSION 3.10)
project(libfms VERSION 0.0.1 LANGUAGES CXX)

message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message("PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

# Global project properties.
include(BuildType.cmake)
include_directories(include) 

add_subdirectory(src)

enable_testing()
add_test(NAME TestTemplate COMMAND test_template)
add_test(NAME TestProb COMMAND test_prob)

#add_library(libfms src/template/template.cpp)
#target_compile_features(libfms PRIVATE cxx_std_17)
#
#target_include_directories(libfms
#    PUBLIC 
#        $<INSTALL_INTERFACE:include>    
#        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#    PRIVATE
#        ${CMAKE_CURRENT_SOURCE_DIR}/src
#)
