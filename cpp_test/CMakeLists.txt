cmake_minimum_required( VERSION 2.8.3 )
project( cpp_test )

set( CMAKE_CXX_FLAGS "-Wall -std=c++14" )

find_package( catkin REQUIRED )

catkin_package(
)

add_executable( cpp_sort src/cpp_sort.cpp)

add_executable( cpp_convert src/cpp_convert.cpp)

add_executable( cpp_2_dimension src/cpp_2_dimension.cpp)
