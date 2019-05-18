// FILE			: shortest_rad.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, May 18 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README
//  This file will test about calculate of circle

// REFERENCE

// MACRO SET

#include    <iostream>

#include    <zeabus/radian.hpp>

int main( int argv, char** argc )
{

    const static unsigned int num_set = 11;

    double start[ num_set ] = { 1 , 2 , 3 , 0 , -1 , -2 , -3 
            , zeabus::radian::pi / 2 , zeabus::radian::pi / 2 * 3 
            , zeabus::radian::pi / -2 , zeabus::radian::pi / 4 };
    double target[ num_set ] = { -3 , -2 , -1 , 0 , 1 , 2 , 3 
            , zeabus::radian::pi / 3 * 2 , zeabus::radian::pi / 4 
            , zeabus::radian::pi / 2 , 0 };

    for( unsigned int run = 0 ; run < num_set ; run++ )
    {
        std::cout   << "Test " << run << "Start : Target <-> " << start[ run ] <<  " : "
                    << target[ run ] << " result is " 
                    << zeabus::radian::different( start[run] , target[run] ) << "\n";
    }

} // main function
