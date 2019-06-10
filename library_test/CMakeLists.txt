cmake_minimum_required( VERSION 2.8.3 )
project( library_test )

set( CMAKE_CXX_FLAGS "-Wall -std=c++14" )

find_package( catkin REQUIRED roscpp tf geometry_msgs)
find_package( zeabus_library_cpp REQUIRED )
find_package( zeabus_library_python REQUIRED )

#message("zeabus_library_cpp_LIBRARIES is ${zeabus_library_cpp_LIBRARIES}")

catkin_package(
    CATKIN_DEPENDS roscpp
)

include_directories(
    ${zeabus_library_cpp_INCLUDE_DIRS}
)

add_executable( test_filter_average src/trimed_mean.cpp)
target_link_libraries( test_filter_average
    ${zeabus_library_cpp_LIBRARIES}
)

add_executable( single_log src/single_log.cpp)
target_link_libraries( single_log
    ${zeabus_library_cpp_LIBRARIES}
)

add_executable( time_test src/time_test.cpp)
target_link_libraries( time_test
    ${zeabus_library_cpp_LIBRARIES}
)

add_executable( diff_rad_test src/shortest_rad.cpp)
target_link_libraries( diff_rad_test
    ${zeabus_library_cpp_LIBRARIES}
)

add_executable( count_test src/count.cpp)
target_link_libraries( count_test 
    ${zeabus_library_cpp_LIBRARIES}
    ${catkin_LIBRARIES}
)

add_executable( quaternion src/quaternion.cpp )
target_link_libraries( quaternion 
    ${zeabus_library_cpp_LIBRARIES}
    ${catkin_LIBRARIES}
)

add_executable( rotation_quaternion src/rotation_quaternion.cpp )
target_link_libraries( rotation_quaternion 
    ${zeabus_library_cpp_LIBRARIES}
    ${catkin_LIBRARIES}
)

add_executable( shutdown src/shutdown.cpp)
target_link_libraries( shutdown ${catkin_LIBRARIES})

catkin_install_python(
    PROGRAMS scripts/quaternion.py
    DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION} 
)
