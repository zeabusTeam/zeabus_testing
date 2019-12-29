// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#define TF_EULER_DEFAULT_ZYX
#include    <tf/LinearMath/Matrix3x3.h>

#include    <ros/ros.h>

#include    <iostream>

#include    <cmath>

int main( int argv ,char** argc )
{

    ros::init( argv , argc , "quaternion" );
    
    unsigned int type; // 0 = quaternion , 1 = euler

    tf::Quaternion quaternion_setup( 0 , 0 , 0 , 1 );
    double temp_x = 0, temp_y = 0, temp_z = 0, temp_w = 0;

    while( ros::ok() )
    {

        std::cout   << "Please input type of your data ( 0 = quaternion , 1 = euler ) : ";
        std::cin    >> type;
        if( type == 0 )
        {
            std::cout   << "input x : "; std::cin >> temp_x;
            std::cout   << "input y : "; std::cin >> temp_y;
            std::cout   << "input z : "; std::cin >> temp_z;
            std::cout   << "input w : "; std::cin >> temp_w;
            quaternion_setup = tf::Quaternion( temp_x , temp_y , temp_z , temp_w );
        }
        else if( type == 1 )
        {
            std::cout   << "input yaw : "; std::cin >> temp_z;
            std::cout   << "input pitch : "; std::cin >> temp_y;
            std::cout   << "input roll : "; std::cin >> temp_x;
            quaternion_setup.setRPY( temp_x , temp_y , temp_z ); // refernece tell 
        }
        else
        {
            std::cout   << "Now have this condition.\n";
        }
        std::cout   << "Your quaternion is : \n";
        std::cout   << "x : " << quaternion_setup.x() << "\n"
                    << "y : " << quaternion_setup.y() << "\n"
                    << "z : " << quaternion_setup.z() << "\n"
                    << "w : " << quaternion_setup.w() << "\n";

        std::cout   << "Please input type of your data want to focus ( 0 : r , 1 : p , 2 : y ) : ";
        std::cin    >> type;
        if( type == 0 )
        {
            
        }
        else if( type == 1 )
        {
            
        }  
        else if( type == 2 )
        {

        }
        else
        {

        }

    } // loop true and easy to canclำ

    ros::shutdown();

    return 0;

}
