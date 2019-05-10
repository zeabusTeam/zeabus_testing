// FILE			: cpp_convert.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, May 10 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README
//  This file will test and learning how to convert type
//  std::basic_stringstream have must to use template please read ref2 to understand about
//      parameter you have to use

// REFERENCE
//  ref1    : https://en.cppreference.com/w/cpp/io/basic_stringstream
//  ref2    : https://en.cppreference.com/w/cpp/string/char_traits
//  ref3    : https://en.cppreference.com/w/cpp/io/manip/setprecision 

#include    <iostream>

#include    <sstream>

#include    <iomanip>

//#define _CONVERT_DOUBLE_
//#define _CONVERT_INT_
#define _CONVERT_PRECISION_

int main( int argv , char** argc )
{
#ifdef _CONVERT_DOUBLE_
    std::basic_stringstream<char> my_stringstream;
    double my_number;
    double second_number;
    std::string my_string;
    std::cout   << "Input data double type : ";
    std::cin    >> my_number;
    my_stringstream << my_number;
    my_stringstream >> my_string;
    my_string += "\n";
    std::cout   << "Output data double type : " << my_string;

    std::cout   << "Input two double type : ";
    std::cin    >> my_number >> my_string;
    my_stringstream << my_number << " " << second_number << "\n";
    my_stringstream >> my_string;
    std::cout   << "Output is : " << my_string << "\n";
#endif // _CONVERT_DOUBLE_

#ifdef _CONVERT_INT_
    std::basic_stringstream<char> int_stringstream;
    std::string int_original_string;
    int int_output_string;
    std::cout   << "Input your integer number : ";
    std::cin    >> int_original_string;

    std::string second_original_string;
    int second_output_string;
    std::cout   << "Input your integer number again : ";
    std::cin    >> second_original_string;

    // convert path
    int_stringstream << second_original_string;
    int_stringstream >> second_output_string;
    std::cout  << "Your second input is " << second_output_string << "\n";
    int_stringstream.clear(); 
    int_stringstream << int_original_string;
    int_stringstream >> int_output_string;
    std::cout   << "Your first input is " << int_output_string << "\n";
    int result = int_output_string + second_output_string;

    std::cout   << "your sum result is " << result << "\n";

#endif // _CONVERT_INT_

#ifdef _CONVERT_PRECISION_
    std::basic_stringstream<char> double_stringstream;
    std::string first_input;
    double first_output;
    std::cout   << "Default precision is " << double_stringstream.precision() << "\n";
    std::cout   << "Input your first double : ";
    std::cin    >> first_input;
    std::cout.precision( 3 );
    double_stringstream << first_input;
    double_stringstream >> first_output;
    std::cout   << "Your output is " << first_output << "\n" ;
#endif // _CONVERT_PRECISION_
}
