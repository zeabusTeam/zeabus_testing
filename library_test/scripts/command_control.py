#!/usr/bin/env python2
# FILE			: command_control.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, June 15 (UTC+0)
# MAINTAINER	: K.Supasan

# README

# REFERENCE

from __future__ import print_function

from zeabus.control.command_interfaces import CommandInterfaces

import rospy

import math

if __name__=="__main__":

    rospy.init_node( "testing_lib" )

    name_node = rospy.get_name()

    auv_control = CommandInterfaces( name_node )

    auv_control.reset_state( 0 , 0)

    auv_control.echo_data()

    print("Now I will absolute yaw to north")

    auv_control.absolute_yaw( math.pi )

    auv_control.echo_data()

    print("I will sleep 5 second")

    rospy.sleep( 5 )

    auv_control.relative_xy( 3 , 1 , True )

    print("I command move forward 3 meter and left 1 meter and sleep 10 second" )

    auv_control.echo_data()

    rospy.sleep(10)

    auv_control.absolute_z( -2 )

    print( "I command to depth 2 meter and sleep 5 second")

    auv_control.echo_data()

    rospy.sleep(5)

