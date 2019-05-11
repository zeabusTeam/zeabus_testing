cmake_minimum_required( VERSION 2.8.3 )
project( library_test )

set( CMAKE_CXX_FLAGS "-Wall -std=c++14" )

find_package( catkin REQUIRED roscpp)
find_package( zeabus_library_cpp REQUIRED )

#message("zeabus_library_cpp_LIBRARIES is ${zeabus_library_cpp_LIBRARIES}")

catkin_package(

)

include_directories(
    ${zeabus_library_cpp_INCLUDE_DIRS}
)

add_executable( test_filter_average src/filter_cut_off_average.cpp)
target_link_libraries( test_filter_average
    ${zeabus_library_cpp_LIBRARIES}
)

add_executable( single_log src/single_log.cpp)
target_link_libraries( single_log
    ${zeabus_library_cpp_LIBRARIES}
)
