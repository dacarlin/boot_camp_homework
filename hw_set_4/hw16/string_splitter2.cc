// This assignment builds on the string splitter function you wrote in
// the previous one.  In this assignment, instead of your input consisting
// of only 1s and 0s, it may now consist of any number of different
// numbers (between 0 and 9).  In this case, you care about the 1s
// and the 0s, but there might be 2s and 3s etc. mixed in.
//
// Your function should report the beginning and ending possition for
// each block of 0s and 1s.  Use the struct below to report a pair of
// positions:

struct start_and_stop {
  int start_;
  int stop_;
};

// So for example, the input string (ignore the two ruler lines)
//
// 00000000001111111111222222222233333333334 <-- ruler tens
// 01234567890123456789012345678901234567890 <-- ruler ones
//
// 00001110293411111887888880000222333311111 <-- the input string
// should report the following starting and stopping
// positions:
// start stop
//     0    3
//     4    6
//     7    7
//    12   16
//    25   28
//    36   40
// Notice that the blocks of non-0s and non-1s are basically ignored.
//
// Your function should have the following signature.
// std::vector< start_and_stop >
// split_zeros_and_ones_blocks_from_string( std::string const & input_string );
//
// Grading will work as it did for the previous assignment -- your int main() will
// be replaced with another one that will call your function and make sure it 
// produces the correct answers.  Think hard about edge cases.

#include <vector>
#include <string>
#include <iostream> 

std::vector< start_and_stop >  
split_zero_and_ones_string( std::string s )
{
    std::vector< start_and_stop > v; 
    for ( int i = 0; i != s.size(); i ++ ) 
    {
        if ( ( s[ i ] != s[ i - 1 ] ) && ( i != 0 ) ) {
            v.push_back( new start_and_stop( 0, 0 ) ); 
        } 
    } 
    return v; 
}

std::vector< start_and_stop >  
split_zeros_and_ones_blocks_from_string( std::string const & input_string )
{
    std::vector< char > v;
    for ( char letter : s ) {
        if ( ( letter == 1 ) || ( letter == 0 ) ) {
            v.push_back( letter ); 
        }
    }

    // now we need to make a string from the vector 
    // and call the function we wrote before 
    std::string clean_s( v.begin(), v.end() ); 
    return split_zero_and_ones_string( clean_s ); 
}

int main() {
    std::vector< std::string > test_strings { "0", "10", "11", "000001111110000111111110000", 
        "00001110293411111887888880000222333311111" }; 
    for ( auto test_string : test_strings ) 
    {
        std::cout << "test string: " << test_string << ", indicies: "; 
        for ( auto index : split_zero_and_ones_string( test_string ) )
            std::cout << index << " "; 
        std::cout << std::endl; 
    } 
    return 0; 
} 

