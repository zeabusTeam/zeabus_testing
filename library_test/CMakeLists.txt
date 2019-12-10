cmake_minimum_required( VERSION 2.8.3 )
project( library_test )

set( CMAKE_CXX_FLAGS "-Wall -std=c++14" )

find_package( catkin REQUIRED roscpp tf geometry_msgs)
find_package( zeabus_library REQUIRED )

catkin_package(
    CATKIN_DEPENDS roscpp
)

include_directories(
    ${zeabus_library_INCLUDE_DIRS}
)
add_executable( outliner src/outliner.cpp)
target_link_libraries( outliner 
    ${catkin_LIBRARIES}
    ${zeabus_library_LIBRARIES}
)
