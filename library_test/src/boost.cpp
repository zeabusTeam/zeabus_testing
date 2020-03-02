// FILE         : boost.cpp
// AUTHOR       : K.Supasan
// CREATE ON    : 2020, FEBUARY 24
// MAINTAINER   : K.Supasan

#include    <zeabus/math/boost/operations.hpp>
#include    <zeabus/math/boost/print_data.hpp>

int main( int argv , char** argc )
{
    boost::qvm::mat< double , 3 , 1 > source1 = { 1 , 2 , 3 };
    boost::qvm::mat< double , 3 , 1 > source2 = { 4 , 5 , 6 };
    boost::qvm::mat< double , 6 , 1 > dest;
    std::cout   << "Before :\n"; zeabus_boost::print( dest );
    zeabus_boost::mat_concat( &dest , source1 , source2 );
    std::cout   << "After :\n"; zeabus_boost::print( dest );
    zeabus_boost::mat_concat( &dest , source2 , source1 );
    std::cout   << "And After :\n"; zeabus_boost::print( dest );
}
