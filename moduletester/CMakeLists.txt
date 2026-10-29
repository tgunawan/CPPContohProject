cmake_minimum_required(VERSION 3.15)
project(ModulFungsi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ModulFungsi
    src/main.cpp
    src/fungsi.cpp
)

target_include_directories(ModulFungsi PRIVATE include)
