cmake_minimum_required(VERSION 3.10)

project(ray)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(ray main.cpp)

target_include_directories( ray PUBLIC
    "${PROJECT_SOURCE_DIR}/includes/"
)