// FILE			: cpp_2_dimension.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, May 27 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <iostream>

#include    <array>

int main( int argv , char** argc )
{
    double run_number = 0;
//  std::array< std::array< double , 5 > , 5 > array_2_dimension;

/*
    for( unsigned int run_x = 0 ; run_x < 5 ; run_x++ )
    {
        for( unsigned int run_y = 0 ; run_y < 5 ; run_y++ )
        {
            array_2_dimension[ run_x ][run_y] = run_number++;
        }
    }
*/

    std::array< std::array< double , 5 > , 5 > array_2_dimension ={
         0 , 1 , 2 , 3 , 4 
        , 5 , 6 , 7 , 8 , 9 
        , 10 , 11 , 12 , 13 , 14
        , 15 , 16 , 17 , 18 , 100
        , 20 , 21 , 21 , 22 , 23
    };
    
    for( unsigned int run_x = 0 ; run_x < 5 ; run_x++ )
    {
        for( unsigned int run_y = 0 ; run_y < 5 ; run_y++ )
        {
            std::cout   << " " <<array_2_dimension[ run_x ][ run_y ];
        }
        std::cout   << "\n";
    }
}
