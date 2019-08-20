#!/usr/bin/env python2
# FILE			: master_control.py
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

    rospy.init_node( "master_test")

    name_node = rospy.get_name()

    auv_control = CommandInterfaces( name_node )

    auv_control.master_call( (False , False , False , True , True , False ) )
