#include <iostream> 
#include <typeinfo> 

class Base 
{
private: 
    int m_id;

public: 
    Base( int id=0 )
        : m_id( id ) 
    {
    }

    int getID() const { return m_id; } 
}; 

class Derived : public Base
{
private: 
    double m_cost; 

public:
    Derived( double cost=.69, int id=69 ) 
        : Base( id ), m_cost( cost ) 
    {
    }

    double getCost() const { return m_cost; } 
}; 

int main() { 

    Derived derived( 1.70, 0 ); 
    derived.getID(); 
    std::cout << derived.getCost() << " " << derived.getID() << std::endl; 

    return 0; 
}
