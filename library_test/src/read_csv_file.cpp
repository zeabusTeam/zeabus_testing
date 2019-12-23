#include    <ros/ros.h>

#include    <cstdlib>

#include    <iostream>

#include    <zeabus/ros/path_file.hpp> // include get_full_path function

#include    <zeabus/file.hpp>

int main( int argv , char** argc )
{

    zeabus::FileCSV fh; // fh is file handle

    std::string path = zeabus_ros::get_full_path( "zeabus_control" , 
            "parameter" , 
            "throttle_force_table.txt" );

    path = zeabus_ros::get_full_path( "library_test" , "parameter" , "test.txt" );

    unsigned int number_column;
    unsigned int num_line;

    std::cout   << "Target file " << path << std::endl;

    fh.open( path );

    int* ptr_integer;
    double* ptr_double;

    std::string buffer_data = "";

    if( fh.is_open() )
    {
        std::cout   << "success open file start at " << fh.tellg() << "\n";
    }
    else
    {
        goto exit_main;
    }

    if( fh.count_column( &number_column ) )
    {
        std::cout   << "Success get column is " << number_column << std::endl;
    }
    else
    {
        goto exit_main;
    }

    if( fh.count_line( &num_line ) )
    {
        std::cout   << "Success get line is " << num_line << std::endl;
    }
    else
    {
        goto exit_main;
    }

    ptr_integer = (int*) malloc( sizeof(int) * num_line );
    ptr_double = (double*) malloc( sizeof(double) * num_line );
    std::cout   << "Finish malloc area\n";
    if( zeabus::extract_csv_type_2( &fh , ptr_integer , ptr_double ) )
    {
        std::cout   << "Success extract table\n";
        for( unsigned int run = 0 ; run < num_line ; run++ )
        {
            std::cout   << ptr_integer[ run ] << "  " << ptr_double[ run ] << "\n";
        }
    }
    else
    {
        goto exit_main;
    }

exit_main:
    return 0;
}
