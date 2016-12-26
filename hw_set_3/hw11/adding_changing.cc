#include <iostream> 

class Base
{
protected:
    int my_value; 

public: 
    Base( int value )
        : my_value = value
    {
    }

    void identify() { std::cout << "I am a Base" << std::endl; } 

}; 

class Derived : public Base 
{ 
public:
    Derived( int value )
        : Base( value ) 
    {
    }
}; 
