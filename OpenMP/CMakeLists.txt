cmake_minimum_required(VERSION 3.10)
project(OpenMPTest)

add_executable(OpenMPTest main.cpp printworld.cpp)

set_source_files_properties(main.cpp PROPERTIES COMPILE_FLAGS "-fopenmp")

set_target_properties(OpenMPTest PROPERTIES LINK_FLAGS "-fopenmp")

