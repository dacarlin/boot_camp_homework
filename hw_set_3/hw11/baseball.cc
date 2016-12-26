#include <string> 
#include <iostream> 

class Person
{ 
private: 
    std::string     name_; 
    int             age_; 

public: 
    Person( std::string name = "", int age = 0 )
        : name_( name ), age_( age )
    {
    }

    std::string getName() const { return name_; } 
    int getAge() const { return age_; } 
}; 

class Actor : public Person
{
private: 
    int oscars_; 
    double rate_; 

public: 
    Actor( std::string name = "", int age = 0, int oscars = 0, double rate = 0 )
        : Person( name, age ), oscars_( oscars ), rate_( rate ) 
    {
    }

    int getOscars() const { return oscars_; }
    double getRate() const { return rate_; } 

};

int main() { 
   
    Person person( "Robert De Niro", 69 ); 
    Actor actor( "Billy Crystal", 55, 4, 10 ); 

    std::cout << actor.getAge() << std::endl; 
    std::cout << person.getAge() << std::endl; 

    return 0; 
} 
