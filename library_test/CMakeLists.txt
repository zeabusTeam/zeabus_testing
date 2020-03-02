cmake_minimum_required( VERSION 2.8.3 )
project( library_test )

set( CMAKE_CXX_FLAGS "-Wall -std=c++14" )

find_package( catkin REQUIRED roscpp tf geometry_msgs)
find_package( zeabus_library REQUIRED )
find_package( zeabus_vision REQUIRED )

catkin_package(
    CATKIN_DEPENDS roscpp
    DEPENDS zeabus_library zeabus_vision
)

include_directories(
    ${zeabus_library_INCLUDE_DIRS}
    ${zeabus_vision_INCLUDE_DIRS}
)
add_executable( outliner src/outliner.cpp)
target_link_libraries( outliner 
    ${catkin_LIBRARIES}
    ${zeabus_library_LIBRARIES}
)

add_executable( csv_file src/read_csv_file.cpp)
target_link_libraries( csv_file 
    ${catkin_LIBRARIES}
    ${zeabus_library_LIBRARIES}
)

add_executable( boost src/boost.cpp)
target_link_libraries( boost 
    ${catkin_LIBRARIES}
    ${zeabus_library_LIBRARIES}
)

add_executable( lib_quaternion src/lib_quaternion.cpp)
target_link_libraries( lib_quaternion 
    ${catkin_libraries}
    ${zeabus_library_LIBRARIES}
)

add_executable( lib_vision src/lib_vision.cpp)
target_link_libraries( lib_vision 
    ${catkin_libraries}
    ${zeabus_library_LIBRARIES}
    ${zeabus_vision_LIBRARIES}
)
