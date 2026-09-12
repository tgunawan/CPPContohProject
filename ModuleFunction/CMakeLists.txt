cmake_minimum_required(VERSION 3.15)
project(ProjectKalkulator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(AplikasiKalkulator
    src/main.cpp
    src/Kalkulator.cpp
    )