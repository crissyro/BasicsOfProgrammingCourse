cmake_minimum_required(VERSION 3.19)
project(untitled2 C)

set(CMAKE_C_STANDARD 11)

add_executable(course main.c)

add_subdirectory(libs)
target_link_libraries(course data_structures)
target_link_libraries(course algoritms)