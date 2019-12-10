// FILE         : outliner.cpp
// AUTHOR       : K.Supasan
// CREATE ON    : 2019, APRIL 8
// MAINTAINER   : K.Supasan

#include    <iostream>

#include    <zeabus/filter/outliner.hpp>

int main( int argv , char** aargc )
{
    zeabus::filter::Outliner< double , 10 > my_filter(0);

    double temp_value;

    my_filter.set_cut_size( 2 );

    while( true )
    {
        std::cout   << "Input integer : ";
        std::cin    >> temp_value;
        my_filter.push_data( temp_value );
        temp_value = my_filter.get_result();
        my_filter.print_data( "All Member is ");
        std::cout   << "Output is " << temp_value << std::endl;
    }
}
