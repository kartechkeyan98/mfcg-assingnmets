cmake_minimum_required(VERSION 3.10)

project(mfcg)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(mfcg main1.cpp)

target_include_directories( mfcg PUBLIC
    "${PROJECT_SOURCE_DIR}/includes/"
)