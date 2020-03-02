// FILE			: lib_vision.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2020, Febuary 27 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <iostream>
#include    <algorithm>
#include    <zeabus/opencv/structure.hpp>
#include    <zeabus/opencv/sort.hpp>
#include    <zeabus/opencv/operations.hpp>
#include    <zeabus/opencv/camera_info.hpp>
#include    <opencv2/core/types.hpp>

int main( int argv , char** argc )
{
    zeabus_opencv::structure::Circle first_circle = { 0 , 0 , 1 };
    zeabus_opencv::structure::Circle second_circle( 5 , 5 , 0.1 );


    std::cout   << "First Circle at " << first_circle.center.x << " , "
                << first_circle.center.y << " have radius " << first_circle.radius << "\n";

    std::cout   << "Distance to of between first and second "
                << first_circle - second_circle << "\n";

    std::vector< zeabus_opencv::structure::Circle > vec_circle;
    vec_circle.push_back( zeabus_opencv::structure::Circle( 1 , 0 , 10 ) );
    vec_circle.push_back( zeabus_opencv::structure::Circle( 3 , 6 , 6 ) );
    vec_circle.push_back( zeabus_opencv::structure::Circle( 3 , 4 , 5 ) );
    
    std::cout   << "Original vector :";
    for( unsigned int run = 0 ; run < vec_circle.size() ; run++ )
    {
        std::cout   << " " << vec_circle[ run ].radius;
    }
    std::cout   << "\n";
    zeabus_opencv::sort::cpp_sort( &vec_circle );
    std::cout   << "After vector :";
    for( unsigned int run = 0 ; run < vec_circle.size() ; run++ )
    {
        std::cout   << " " << vec_circle[ run ].radius;
    }
    std::cout   << "\n";

    cv::Point2f test_1( 3 , 4 );
    cv::Point2f test_2( 9 , 8 );
    cv::Point2f result = test_2 - test_1;
    std::cout   << "Result " << result.x << " : " << result.y << "\n";

    std::vector< cv::Point2f > vec_center;
    zeabus_opencv::operations::pull_center( vec_circle , &vec_center );
    std::cout   << "Center vector :";
    for( unsigned int run = 0 ; run < vec_center.size() ; run++ )
    {
        std::cout   << " (" << vec_center[ run ].x << "," << vec_center[run].y << ")";
    }
    std::cout   << "\n";
    zeabus_opencv::sort::center( &vec_center );
    std::cout   << "Answer vector :";
    for( unsigned int run = 0 ; run < vec_center.size() ; run++ )
    {
        std::cout   << " (" << vec_center[ run ].x << "," << vec_center[run].y << ")";
    }
    std::cout   << "\n";

    vec_center.assign( vec_center.begin() + 1 , vec_center.begin() + 3 );
    std::cout   << "Assign vector :";
    for( unsigned int run = 0 ; run < vec_center.size() ; run++ )
    {
        std::cout   << " (" << vec_center[ run ].x << "," << vec_center[run].y << ")";
    }
    std::cout   << "\n";

    std::cout   << "Next test about camera info\n";
    std::cout   << "cv::Mat camera_infomation have row " 
                << zeabus_opencv::front::mat_distor.rows << " and column "
                << zeabus_opencv::front::mat_distor.cols << "\n";
    for( int row = 0 ; row < zeabus_opencv::front::mat_distor.rows ; row++ )
    {
        std::cout   << "\t";
        for( int col = 0 ; col < zeabus_opencv::front::mat_distor.cols ; col++ )
        {
            printf( "%15.4f" , *zeabus_opencv::front::mat_distor[ row * 3 + col ] );
        }
        std::cout   << "\n";
    }
}
