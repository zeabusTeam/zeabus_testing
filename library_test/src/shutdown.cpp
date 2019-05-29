// FILE			: shutdown.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, May 29 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <iostream>

#include    <ros/ros.h>

int main( int argv , char** argc )
{
    ros::init( argv , argc , "node_shutdown" );

    ros::NodeHandle my_handle;

    if( my_handle.ok() )
    {
        std::cout   << "Oh my handle are ok\n";
    }
    else
    {
        std::cout   << "Oh I'm don't ok\n";
    }

    ros::shutdown();
    std::cout   << "Oh shutdown!!\n";

    if( my_handle.ok() )
    {
        std::cout   << "Oh my handle are ok\n";
    }
    else
    {
        std::cout   << "Oh I'm don't ok\n";
    }

    ros::shutdown();
    return 0;
}
