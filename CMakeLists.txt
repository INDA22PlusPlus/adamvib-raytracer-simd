cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 20)

project(raytracer123
    VERSION 1.0.0
    DESCRIPTION "A simple ray tracer"
    LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(
    nanobench
    GIT_REPOSITORY https://github.com/martinus/nanobench.git
    GIT_TAG v4.1.0
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(nanobench)

set(source_dir "${PROJECT_SOURCE_DIR}/Source Files")
set(source_files ${source_dir}/Main.cpp ${source_dir}/Light.cpp ${source_dir}/Object.cpp ${source_dir}/Plane.cpp ${source_dir}/Scene.cpp ${source_dir}/Vector3.cpp ${source_dir}/Ray.cpp ${source_dir}/Sphere.cpp  ${source_dir}/Camera.cpp ${source_dir}/Material.cpp)

add_executable(raytracer ${source_files})

target_include_directories(raytracer PUBLIC "Header Files/") 
target_link_libraries(raytracer nanobench)