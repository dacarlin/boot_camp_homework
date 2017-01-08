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

using namespace std; 

vector< start_and_stop >
split_zeros_and_ones_blocks_from_string( string const & input_string ) 
{
    // we'll need a vector to hold things
    // and initial values for start and stop positions 
    vector< start_and_stop > v;
    int start { -1 };
    int stop { -1 }; 

    // loop over the digits in the input string 
    for ( int i=0; i!=input_string.size(); i++ ) 
    {
        if ( ( input_string[i] == '0' ) || ( input_string[i] == '1' ) )
        // ignore digits other than 0 and 1 
        {
            if ( input_string[i] != input_string[i-1] ) start = i; 
            if ( input_string[i] != input_string[i+1] ) stop = i; 
        }

        if ( ( start > -1 ) && ( stop > -1 ) )
        // if both start and stop positions have been set for this digit 
        // create a new struct and append to vector 
        {
            v.push_back( start_and_stop { start, stop } ); 
            // reset start and stop for next one 
            start = -1; 
            stop = -1; 
        }
    }

    // print results 
    cout << "input string: " << input_string << "\nstart stop" << endl; 
    for ( auto dat : v ) 
        cout << dat.start_ << " " << dat.stop_ << endl; 

    return v; 
}

int main()
{   
    vector< string > test_strings { "0", "1", "00001110293411111887888880000222333311111" }; 
    for ( auto str : test_strings )
        split_zeros_and_ones_blocks_from_string( str ); 
    return 0; 
}
