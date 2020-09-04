cmake_minimum_required(VERSION 3.13)
project(informatik_projekt)

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../hog2)
add_executable(informatik_projekt main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../hog2/apps/delta/Driver.cpp )

