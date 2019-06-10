#!/usr/bin/env python2
# FILE			: quaternion.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, June 10 (UTC+0)
# MAINTAINER	: K.Supasan

# README

# REFERENCE

from __future__ import print_function

from zeabus.math.quaternion import Quaternion

if __name__ == "__main__":
    print( "Welcome to library test package for testing python lib Quaternion" )

    current_quaternion = Quaternion()
    current_quaternion.set_quaternion( (0, 0, 0.707, 0.707) )
    current_quaternion.normalize()
    current_quaternion.print_quaternion( "current_quaternion" )

    target_quaternion = Quaternion()
    target_quaternion.set_euler( 1.57 , 0.2 , 0.1 )
    target_quaternion.print_quaternion( "target_quaternion" )

    diff_quaternion = target_quaternion * current_quaternion.inverse()
    diff_quaternion.print_quaternion( "diff_quaternion")

    current_euler = current_quaternion.get_euler()
    diff_euler = diff_quaternion.get_euler()
    target_euler = target_quaternion.get_euler()

    print( "Euler target is {:6.3f} {:6.3f} {:6.3f}".format( 
        target_euler[0] 
        , target_euler[1] 
        , target_euler[2] ) ) 

    print( "Euler current is {:6.3f} {:6.3f} {:6.3f}".format( 
        current_euler[0] 
        , current_euler[1] 
        , current_euler[2] ) ) 

    print( "Euler different is {:6.3f} {:6.3f} {:6.3f}".format( 
        diff_euler[0] 
        , diff_euler[1] 
        , diff_euler[2] ) ) 
