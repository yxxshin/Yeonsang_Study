cmake_minimum_required(VERSION 3.0)
project(example)
set(CMAKE_BUILD_TYPE Release)

find_package(PythonInterp REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_subdirectory(pybind11)
pybind11_add_module(example1 Ex1_first_steps.cpp)
pybind11_add_module(example2_1 Ex2_object_oriented_code_1.cpp)
pybind11_add_module(example2_2 Ex2_object_oriented_code_2.cpp)
pybind11_add_module(example2_3 Ex2_object_oriented_code_3.cpp)
