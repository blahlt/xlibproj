cmake_minimum_required(VERSION 2.6)

project(project2)

find_package(X11)

if(NOT X11_FOUND)
  message(FATAL_ERROR "Failed to find X11 which is required")
endif(NOT X11_FOUND)

add_subdirectory(src)
