#include    <iostream>

#include    <vector>

int main( int argv , char** argc )
{
    std::vector< unsigned int > temp_vector;
    temp_vector.assign( 8 , 0 );
    temp_vector.at( 5 ) = 10;
    for( unsigned int run = 0 ; run < 8 ; run++ )
    {
        std::cout   << temp_vector.at( run ) << " " ;
    }
    std::cout   << "\n";
}
