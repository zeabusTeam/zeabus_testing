// FILE			: rotation_quaternion.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, Jun 7 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#define TF_EULER_DEFAULT_ZYX
#include    <tf/LinearMath/Matrix3x3.h>

#include    <geometry_msgs/PoseStamped.h>

#include    <ros/ros.h>

#include    <iostream>

void print_quaternion( std::string message , tf::Quaternion* quaternion )
{
    std::cout   << message << " " << quaternion->x() << " " << quaternion->y()
                << " " << quaternion->z() << " " << quaternion->w() << "\n";
} // function print_quaternion

int main( int argv , char** argc )
{

    ros::init( argv , argc , "quaternion" );

    // Constructor x y z w
    // we have linear value in enu convention of body frame
    tf::Quaternion linear_value( 3 , 2 , 1 , 0 );
    
    print_quaternion( "Linear quaternion" , &linear_value );

    tf::Quaternion odmom_base_link( 1.57075 , 0 , 0 );

    tf::Quaternion normal_answer = odmom_base_link * linear_value * odmom_base_link.inverse();

    tf::Quaternion inverse_answer = odmom_base_link.inverse() * linear_value * odmom_base_link;

    print_quaternion( "rotation" , &odmom_base_link );

    print_quaternion( "normal_answer" , &normal_answer ); 

    print_quaternion( "inverse_answer" , &inverse_answer ); 

    return 0;
}
