// FILE         : filter_cut_off_average.cpp
// AUTHOR       : K.Supasan
// CREATE ON    : 2019, APRIL 8
// MAINTAINER   : K.Supasan

#include    <iostream>

#include    <zeabus/filter/cut_off_average.hpp>

int main( int argv , char** aargc )
{
    zeabus::filter::CutOffAverage< int , 10 > my_filter(2);

    int temp_value;

    while( true )
    {
        std::cout   << "Input integer : ";
        std::cin    >> temp_value;
        my_filter.push( temp_value );
        temp_value = my_filter.get_result();
        std::cout   << "Output is " << temp_value << std::endl;
    }
}
