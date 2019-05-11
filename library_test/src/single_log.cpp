// FILE			: single_log.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, May 11 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

#include    <iostream>

#include    <zeabus/ros_interfaces/file/single_filter.hpp>

#include    <zeabus/filter/cut_off_average.hpp>

int main( int argv , char** argc )
{

    zeabus::ros_interfaces::file::SingleFilter log_file;

    (void)log_file.setup_package("zeabus_log");
    log_file.setup_subdirectory( "log/filter" );
    log_file.setup_file_name( "testing.txt" );
    log_file.open();

    zeabus::filter::CutOffAverage< double , 10 > filter;
    (void)filter.setup_cutoff(2);

    log_file.write_column( "input" , "output");
    ros::Time time;

    std::cout   << "run 0 to 9\n";

    for( unsigned int run = 0 ; run < 10 ; run++ )
    {
       log_file.logging( ros::Time::now() , run*1.0 , filter.push(run) ); 
    }

    std::cout   << "finish\n";
}
