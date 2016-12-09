#include <iostream>

// In this assignment, you will write the recursive version of the Fibonacci function.
// The ith Fibonacci number is defined as the sum of the i-1th and the i-2th Fibonacci
// numbers.  The 1st Fibonacci number is 1.  The second Fibonacci number is 1.  Then,
// for example, the third Fibonacci number is 2 -- the sum of the first and second.
// Your code should check the value of the input number and return 1 if it's either 1 or 2.
// If it's not either 1 or 2, then you will have the function return the sum of two calls
// to the function!  Functions calling themselves?  Of course!
// Please write the recursive version of this function. (You'll later compute this in a
// non-recursive way; but for this assignment, use the recursive function).

// Your function, fib, should take an integer and return an integer.  The integer it
// takes represents which Fibonacci number should be computed; e.g. if it's 10, then
// the 10th fibonacci number should be returned.

// How long does it take to compute the 20th Fibonacci number?  The 40th?

// Answer: The 20th, maybe a millisecond or less? The 40th, about a second. 

// Wrap the call to fib(which) in a for loop so that you can call the function 100 times.
// Surround this for loop with two calls to the clock() function in <ctime>.  Using
// the CLOCKS_PER_SEC constant, measure the running time for a single call to "fib" as
// a function of the input value, "which."  Plot this running time for values of which
// between 10 and 40 and submit an image file (e.g. a .png) with this graph.  If 100
// is too small a number of iterations to accurately measure the running time, try
// increasing this count.

#include <ctime> 

int fib( int i ) {
  if ( i < 3 ) { 
    return 1; 
  } else { 
    return fib( i-1 ) + fib( i-2 ); 
  }
}

double time( int fib_number ) {
  std::clock_t start; 
  double duration; 
  double n_iter = 100; 
  start = std::clock(); 
  for ( int i = 0; i < n_iter; i ++ ) { fib( fib_number ); }
  duration = ( std::clock() - start ) / ( double ) CLOCKS_PER_SEC; 
  return duration / n_iter; 
} 

int main() {
  std::cout << "Enter the nth Fibonacci number you would like: ";

  int which;
  std::cin >> which;

  std::cout << "The " << which << "th Fibonacci number is: " << fib( which ) << std::endl;

  std::cout << time( which ) << " seconds (average of 100 iterations)"; 

  std::cout << "Now producing data for graph for homework ..." << std::endl; 

  std::cout << "fib_number\trun_time" << std::endl; 
  for ( int i = 10; i <= 40; i ++ ) {
    std::cout << i << "\t" << time( i ) << std::endl; 
  }

  return 0;
}
