// FILE			: time_test.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, May 11 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

#include    <iostream>

#include    <zeabus/time.hpp>

int main( int argv , char** argc )
{
    std::cout   << "Print all type_case\n";
    std::string result;
    for( unsigned int run = 1 ; run < 7 ; run++ )
    {
        result = zeabus::local_time( run );
        std::cout   << "------------------------------->RUN " << run <<  " : " << result << "\n";
    }
}
