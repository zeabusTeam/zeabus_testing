// FILE			: quaternion.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, May 28 (UTC+0)
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

int main( int argv , char** argc )
{

    ros::init( argv , argc , "quaternion" );

    ros::NodeHandle node_handlle;

    ros::Publisher enu_pub = node_handlle.advertise< geometry_msgs::PoseStamped >("enu" , 10 );
    ros::Publisher origin_pub 
            = node_handlle.advertise< geometry_msgs::PoseStamped >("origin" , 10 );
    geometry_msgs::PoseStamped enu_msg;
    geometry_msgs::PoseStamped origin_msg;
 
    enu_msg.header.frame_id = "odom";
    enu_msg.pose.position.x = 0;
    enu_msg.pose.position.y = 0;
    enu_msg.pose.position.z = 1;
    enu_msg.pose.orientation.x = 0;
    enu_msg.pose.orientation.y = 0;
    enu_msg.pose.orientation.z = 0;
    enu_msg.pose.orientation.w = 1;

    // Constructor x y z w
    tf::Quaternion linear_value( 0 , 0 , 1 , 0 );
    
    tf::Quaternion ned_to_enu( 0.7071 , 0.7071 , 0 , 0 );

    tf::Quaternion enu_quaternion;

    tf::Quaternion ned_quaternion;

    std::cout   << "Please input your roll pitch yaw : ";
    double RPY[3];
//    std::cin    >> RPY[0] >> RPY[1] >> RPY[2];
//    ned_quaternion = tf::Quaternion( RPY[2] , RPY[1] , RPY[0] );

    ned_quaternion = tf::Quaternion( 1.57 , 0.0 , 0.0 );
    enu_quaternion = ned_to_enu * ned_quaternion;

    std::cout   << "NED SYSTEM : ";
    std::cout   << "\tQuaternion : " << ned_quaternion.x() << " " << ned_quaternion.y() << " "
                << ned_quaternion.z() << " " << ned_quaternion.w() << "\n";
    tf::Matrix3x3( ned_quaternion ).getRPY( RPY[0] , RPY[1] , RPY[2] );
    std::cout   << "\tRPY        : " << RPY[0] << " " << RPY[1] << " " << RPY[2] << "\n";

    std::cout   << "ENU SYSTEM : ";
    std::cout   << "\tQuaternion : " << enu_quaternion.x() << " " << enu_quaternion.y() << " "
                << enu_quaternion.z() << " " << enu_quaternion.w() << "\n";
    tf::Matrix3x3( enu_quaternion ).getRPY( RPY[0] , RPY[1] , RPY[2] );
    std::cout   << "\tRPY        : " << RPY[0] << " " << RPY[1] << " " << RPY[2] << "\n";

    std::cout   << "Next part of vector rotation\n";
    tf::Quaternion temp;
    temp = ned_quaternion * linear_value * ned_quaternion.inverse();
    std::cout   << "Origin linear : " << linear_value.x() << " " << linear_value.y()
                << " " << linear_value.z() << "\n";
    std::cout   << "NED linear    : " << temp.x() << " " << temp.y() << " " << temp.z() << "\n"; 
    temp = enu_quaternion.inverse() * linear_value * enu_quaternion;
    std::cout   << "ENU linear    : " << temp.x() << " " << temp.y() << " " << temp.z() << "\n";

    origin_msg.header.frame_id = "odom";
    origin_msg.pose.position.x = temp.x();
    origin_msg.pose.position.y = temp.y();
    origin_msg.pose.position.z = temp.z();
    origin_msg.pose.orientation.x = enu_quaternion.x();
    origin_msg.pose.orientation.y = enu_quaternion.y();
    origin_msg.pose.orientation.z = enu_quaternion.z();
    origin_msg.pose.orientation.w = enu_quaternion.w();

    ros::Rate rate( 10 );
    while( node_handlle.ok() )
    {
        rate.sleep();
        origin_msg.header.stamp = ros::Time::now();
        enu_msg.header.stamp = ros::Time::now();
        enu_pub.publish( enu_msg );
        origin_pub.publish( origin_msg );
    }
    ros::shutdown(); 

    return 0;
}
