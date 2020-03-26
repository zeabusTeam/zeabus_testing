// FILE			: lib_quaternion.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2020, Febuary 25 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#define TF_EULER_DEFAULT_ZYX
#include    <tf/LinearMath/Matrix3x3.h>

#include    <geometry_msgs/PoseStamped.h>

#include    <zeabus/math/quaternion.hpp>

#include    <std_msgs/String.h>

#include    <ros/ros.h>

#include    <iostream>

int main( int argv , char** argc )
{
    tf::Quaternion temp_quaternion( -0.003 , -0.948 , 0.316 , -0.032 );
    std::cout   << "Quaternion    : -0.003 , -0.948 , 0.316 , -0.032 \n"
                << "Euler ZYX     : -3.127 , 0.063 , -2.498\n";
    double roll , pitch , yaw; 
    zeabus::math::get_euler( temp_quaternion , &roll , &pitch , &yaw );
    std::cout   << "zeabus lib " << roll << " , " << pitch << " , " << yaw << "\n";
    tf::Matrix3x3( temp_quaternion ).getRPY( roll , pitch , yaw );
    std::cout   << "tf lib " << roll << " , " << pitch << " , " << yaw << "\n";

    double test[10] = { 0 , 0 , 0 , 0 , 6 , 10 , 0 , 0 , 0 , 0 };
    boost::array< double , 3 > test_array = { 0 , 6 , 10 };
    tf::Quaternion quat_rotation( 0.0 , 0.0 , 0.247 , 0.969 );

    zeabus::math::rotation( quat_rotation , &test_array );
    zeabus::math::rotation( quat_rotation , &test[3] );
 
    std::cout   << "X === " << test[ 3 ] << "  : " << test_array[ 0 ] << "\n"; 
    std::cout   << "Y === " << test[ 4 ] << "  : " << test_array[ 1 ] << "\n"; 
    std::cout   << "Z === " << test[ 5 ] << "  : " << test_array[ 2 ] << "\n"; 

    std::cout   << "zeabus library test create quaternion convention yaw pitch roll\n";
    roll = 1.0;
    pitch = 0.4;
    yaw = -2.0;
    std::cout   << "Target roll pitch yaw " << roll << " : " << pitch << " : " << yaw << "\n";
    zeabus::math::get_quaternion( roll , pitch , yaw , &temp_quaternion );
    std::cout   << "zeabus_lib :\n" 
                << "\tx : " << temp_quaternion.x() << "\n"
                << "\ty : " << temp_quaternion.y() << "\n"
                << "\tz : " << temp_quaternion.z() << "\n"
                << "\tw : " << temp_quaternion.w() << "\n";
    temp_quaternion = tf::Quaternion( yaw , pitch , roll );
    std::cout   << "tf_lib :\n" 
                << "\tx : " << temp_quaternion.x() << "\n"
                << "\ty : " << temp_quaternion.y() << "\n"
                << "\tz : " << temp_quaternion.z() << "\n"
                << "\tw : " << temp_quaternion.w() << "\n";
}
