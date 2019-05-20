// FILE			: count.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, May 20 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README
//  This file will test count.hpp

// REFERENCE

// MACRO SET

#include    <iostream>

#include    <zeabus/count.hpp>

#include    <ros/ros.h>


int main( int argv , char** argc )
{
    ros::Time::init();
    ros::Time time = ros::Time::now();
    bool result;
    for( unsigned int run = 0 ; run < 5 ; run++ )
    {
        (void)zeabus::count::compare( time , 3 , &result );
        if( result )
        {
            std::cout   << "Test don't over now\n";
        }
        else
        {
            std::cout   << "Test over now\n";
        }
    }
}
