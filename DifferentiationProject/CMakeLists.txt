cmake_minimum_required(VERSION 3.20)
project(DifferentiationProject LANGUAGES CXX)

add_library(Differentiation SHARED
    src/Differentiation.cpp
)

target_compile_definitions(Differentiation PRIVATE DIFFERENTIATION_EXPORTS)

target_include_directories(Differentiation PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(Differentiation PUBLIC cxx_std_20)