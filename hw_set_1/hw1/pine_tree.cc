#include <iostream>

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

  // if the pine tree is of height n
  // there will be n rows of stars 
  // and one tree trunk 

  // for the kth row of stars, the number of stars 
  // is 2k + 1 

  int final_number_of_stars = ( 2 * height ) + 1; 

  for ( int i=0; i < height; i++ ) {
    // for each row of the tree 
    // there will be 2i + 1 stars on this level 
    // there will be ( final_number_of_stars - 1 ) / 2 spaces on this level 

    for ( int s=0; s < (final_number_of_stars - ( 2 * j + 1 ) ); s++ ) {
      std::cout << ' '; 
    }

    for ( int j=0; j < (2 * i) + 1; j++ ) {
      // for each star
      // print the star 
      std::cout << '*'; 
    }
    // print a new line for this row
    std::cout << '\n'; 
  }

  // finally, print the tree trunk 
  std::cout << '|'; 

  return 0;
}
