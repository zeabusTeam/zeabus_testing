cmake_minimum_required( VERSION 2.8.3 )
project( wx_widgets_test )

set( CMAKE_CXX_FLAGS "-Wall -std=c++14" )

find_package( catkin REQUIRED )

find_package( wxWidgets REQUIRED )

catkin_package(
)

include_directories(
    ${wxWidgets_INCLUDE_DIRS}
)

message( "INCLUDE is ${wxWidgets_INCLUDE_DIRS}")
message( "LIBRARIES is ${wxWidgets_LIBRARIES}")

add_definitions( -DWXUSINGDLL -D__WXGTK2__ -D__WXGTK__ )

add_executable( cpp_wx src/cpp_wxWidgets.cpp)
target_link_libraries( cpp_wx ${wxWidgets_LIBRARIES} )

add_executable( first_wx src/first_wxWidgets.cpp )
target_link_libraries( first_wx ${wxWidgets_LIBRARIES} )
