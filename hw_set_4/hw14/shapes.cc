#include <iostream>
#include <math.h> 

class shape {
public:
  float get_area(){return area_;} //Getter function: returns the area stored in area_

protected:

  // Setter function: changes the value of the area stored in area_
  // what does it meant that this function is protected?

  // Ans. It can only be accessed by this class and derived classes 
    
  float set_area(float a){area_ = a;} 

private:
  float area_;
};

//write a derived class rectangle from the base class shape
class rectangle : public shape{
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
            return ( a_ + b_ + c_ ) / 2; 
        } else {
            return -1; 
        } 
    } 

private: 
    float a_; 
    float b_; 
    float c_; 
}; 

