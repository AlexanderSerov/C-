cmake_minimum_required(VERSION 3.0.0)
project(BoostHello VERSION 0.1.0)

find_package(Boost REQUIRED COMPONENTS system filesystem)

add_executable(BoostHello boostHelloWorld.cpp)

target_link_libraries(BoostHello ${Boost_LIBRARIES})

if (Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
endif ()

