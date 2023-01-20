cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 20)

project(raytracer
    VERSION 1.0.0
    DESCRIPTION "A simple ray tracer"
    LANGUAGES CXX
)

include_directories(Header\ Files)

add_subdirectory(Source\ Files)