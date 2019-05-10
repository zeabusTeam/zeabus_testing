// FILE         : cpp_sort.cpp
// AUTHOR       : K.Supasan
// CREATE ON    : 2019, MAY 10
// MAINTAINER   : K.Supasan

#include    <iostream>

#include    <algorithm>

int main( int argv , char** argc )
{

    unsigned int size_array = 10;
    int array[ size_array ] = {10, 9, 3, 8 ,4 ,6 ,7 ,9 ,1 };

    std::cout   << "Before sort :";
    for( unsigned int run = 0 ; run < size_array ; run++ )
    {
        std::cout   << " " << array[run];
    }
    std::cout   << "\n";

    std::cout   << "First position is " << array << "\n";
    std::cout   << "Last position is " << array + size_array << "\n";
    std::sort( array , array + size_array );

    std::cout   << "After sort :";
    for( unsigned int run = 0 ; run < size_array ; run++ )
    {
        std::cout   << " " << array[run];
    }
    std::cout   << "\n";
}
