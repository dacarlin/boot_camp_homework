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

// Question: Why does the whats_area() function in the rectangle class generate an error?
// Answer: `whats_area()` in the rectangle class doesn't have access to the variable 
//         because `area_` is marked `private` in the base class (`shape`) 

#include <iostream>
#include <math.h> 

class shape {
public:
  float get_area(){return area_;} //Getter function: returns the area stored in area_

protected:

  // Setter function: changes the value of the area stored in area_
  // what does it meant that this function is protected?
  // It can only be accessed by this class and derived classes 
    
  float set_area(float a){area_ = a;} 

private:
  float area_;
};

//write a derived class rectangle from the base class shape
class rectangle : public shape {
public:
  // note that the rectangle is responsible for informing the base class of its area
  rectangle( float b, float h ) { base_ = b; height_ = h; set_area( calculate_area() ); } //constructor that sets-up default values

  float calculate_area() {return base_ * height_;} //calculates the area of a rectangle using the formula base*height

  //float whats_area(){return area_;} //THIS LINE WILL NOT COMPILE. Why not?

  void set_base( float b ) { base_ = b; set_area( calculate_area() ); }
  void set_height( float h ) { height_ = h; set_area( calculate_area() ); }

private:
  float base_;
  float height_;
};

// Write a derived class, circle, from the base class shape. A circle can be defined
// by a single radius and thus the constructor should take a single argument and assign
// the value to the radius. There should also be a calculate_area function that
// calculates the area of the circle.

class circle : public shape 
{
public:
    circle( float r = -1 ) : shape() 
    {
        radius_ = r; 
        set_area( calculate_area() ); 
    }

    float calculate_area()
    {
        return M_PI * radius_ * radius_; 
    }

    void set_radius( float r )
    {
        radius_ = r; 
        set_area( calculate_area() );
    }
    
private: 
    float radius_; 
}; 

// Write a derived class, triangle, from the base class shape.  A triangle can be
// defined by the lengths of its three sides.  Make sure your triangle is able to
// calculate its area.  If the three lengths do not define a proper triangle (e.g.
// if one lenght is 1 another length is 2 and the third length is 100, then you
// don't have a closed triangle), then set the area to be -1.

class triangle : public shape 
{
public: 
    triangle( float len1, float len2, float len3 ) : shape ()
    {
        a_ = len1; 
        b_ = len2; 
        c_ = len3; 
        set_area( calculate_area() ); 
    }

    float calculate_area() 
    {
        if ( ( a_ + b_ > c_ ) && ( a_ + c_ > b_ ) && ( b_ + c_ > a_ ) ) {
        // we define a valid triangle as one where each side is shorter than 
        // the sum of the other two sides, else return -1 for the area 
            double s; 
            double A; 
            s = ( a_ + b_ + c_ ) / 2; 
            A = pow( s * (s - a_) * (s - b_) * (s - c_), 0.5 ); 
            // Heron's formula 
            return A; 
        } else {
            return -1; 
        } 
    } 

private: 
    float a_; 
    float b_; 
    float c_; 
}; 

int main(){
  
  float user_base, user_height;

  std::cout << "Please enter a base length: ";
  std::cin >> user_base;
  std::cout << "Please enter a height: ";
  std::cin >> user_height;

  //Create rectangle object
  rectangle rec1(user_base, user_height);

  //Test your circle class
  float user_radius;
  std::cout << "Please enter a circle radius: ";
  std::cin >> user_radius;

  //create an object of the circle class with radius equal to user_radius
  circle cir1( user_radius ); 
  
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

  triangle tri1( length1, length2, length3 ); 

  std::cout << "The area of the rectangle is: " << rec1.get_area() << std::endl;
  std::cout << "The area of the circle is: " << cir1.get_area() << std::endl;
  std::cout << "The area of the triangle is: " << tri1.get_area() << std::endl;
  

  return 0;

}
