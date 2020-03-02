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

}
