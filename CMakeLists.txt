cmake_minimum_required(VERSION 3.19)
project(SummerSchool)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 main.cpp)

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
