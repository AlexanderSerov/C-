cmake_minimum_required(VERSION 3.0.0)
project(Squares VERSION 0.1.0)

find_package(OpenCV REQUIRED)

add_executable(Squares OpenCVHelloWorld.cpp)

target_link_libraries(Squares ${OpenCV_LIBS})