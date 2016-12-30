// In this exercise, you will be working with classes and derived classes.
// Inheritance is an important concept in object-oriented design
// because it allows us to define one class in terms of another class.
// Conceptually, one class ought to derive from another class if it passes
// the "is a" test.  If you can say X is a Y, then X should derive from Y.
// For instance, a "Dog" is a "Mammal".  It would be appropriate to encode
// this relationship by by creating a "Dog" class as a derivative of
// the "Mammal" class.

// Here are a few references to get you started on this concept:
// http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
// http://en.wikibooks.org/wiki/C%2B%2B_Programming/Classes/Inheritance

// For this exercise, we can think of a "triangle" and a "rectangle" as
// derivatives of the parent class "shape".

// Your mission, should you choose to accept it, will be to define two classes
// circle and triangle that will calculate the area of a circle and a triangle.
// This area will be stored in a private member variable defined in the
// parent class "shape", which will only be accessible by the base classe's get_area
// and set_area functions. You will test your new derived classes by creating
// instances of each in main() and printing their areas.

// Question (Answer here): 
// Why does the whats_area() function in the rectangle class generate an error?

// For Homework 14, You should create a separate cc file that contains your base
// and derived classes. For this exercise, you should add a pure virtual function
// to the base class called "name", which returns a string giving the name for the
// class. You'll use this to make reporting the areas of your objects easier: you
// can construct a std::vector< shape * > and load up the individual instances
// (constructed using "new" and put into pointers) into this vector.  Then you can
// use a for loop to visit each shape and to output its name and its area.  The
// output should remain identical to that in hw13, but it should come from a for loop
// instead of from individual cout statements.


#include <iostream>
#include "shapes.cc" 
#include <vector> 

int main(){

  std::vector< shape * > v; 
  
  float user_base, user_height;

  std::cout << "Please enter a base length: ";
  std::cin >> user_base;
  std::cout << "Please enter a height: ";
  std::cin >> user_height;

  //Create rectangle object and put it into the vector of shape *'s
  // this line will not work, but it's close: rectangle rec1(user_base, user_height);
  v.push_back( new rectangle { user_base, user_height } ); 

  //Test your circle class
  float user_radius;
  std::cout << "Please enter a circle radius: ";
  std::cin >> user_radius;

  //create an object of the circle class with radius equal to user_radius
  v.push_back( new circle { user_radius } ); 
  
  // Test your triangle class
  float length1, length2, length3;
  std::cout << "Please enter length 1 for your triangle: ";
  std::cin >> length1;
  std::cout << "Please enter length 2 for your triangle: ";
  std::cin >> length2;
  std::cout << "Please enter length 3 for your triangle: ";
  std::cin >> length3;

  // create an object of the triangle class with the three lengths.
  // Your triangle class should probably make sure that these lengths
  // are sensical.  (do the distances satisfy the "triangle inequality"?)
  v.push_back( new triangle { length1, length2, length3 } ); 

  // Replace the following statements with a for loop
  //std::cout << "The area of the rectangle is: " << rec1.get_area() << std::endl;
  //std::cout << "The area of the circle is: " << cir1.get_areastd::endl;
  //std::cout << "The area of the triangle is: " << std::endl;

  for ( auto my_shape : v ) 
    std::cout << my_shape->get_area() << std::endl; 

  // Now iterate across the vector and delete all the objects pointed to by it;
  // you should not leak memory.
  for ( auto my_shape : v ) { // type of v is `shape`
    delete my_shape; 
    my_shape = 0; 
  }

  return 0;

}
