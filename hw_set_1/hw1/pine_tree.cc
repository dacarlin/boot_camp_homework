#include <iostream>
#include <string> 

int main() {
  
  std::cout << "Enter the pine tree's height as an integer: ";
  int height;
  std::cin >> height;

  // Assignment:
  // Write code here to draw a pine tree.
  // If the height given is "3" then the pine tree should look like this:
  //   *
  //  ***
  // *****
  //   |
  //
  // If the height given is "5" then the pine tree should look like this:
  //     *
  //    ***
  //   *****
  //  *******
  // *********
  //     |
  //
  // where the height represents the number of rows of stars.  The trunk should
  // always be there.  Don't worry about writing code to verify that the input
  // is an integer (though, kudos if you did think about that being necessary!)

  for ( int i = 0; i <= height; i++ ) {
    if ( i == height ) { 
      std::cout << std::string( i, ' ' ) << "|"; 
    } else { 
      std::cout << std::string( height - i, ' ' ) << std::string( 2 * i + 1, '*' ) << std::endl; 
    }
  }
  return 0;
}
