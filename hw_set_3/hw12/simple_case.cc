#include <iostream> 

// class Pet, definition
// base class for all pets 

class Pet
{ 
private: 
    double age_; 
    double weight_; 

public: 
    double get_age(); 
    double get_weight(); 
    int lives_; 
    int get_lives(); 
    void set_lives( int ); 

protected: 
    void set_age( double ); 
    void set_weight( double ); 
}; 


// class Pet, getters (in "public", above) 

double
Pet::get_age()
{
    return age_; 
} 

double
Pet::get_weight()
{
    return weight_; 
} 

int 
Pet::get_lives()
{
    return lives_; 
} 

// class Pet, setters (protected, above) 

void 
Pet::set_age( double time )
{
    age_ += time; 
}

void 
Pet::set_weight( double wt )
{
    weight_ = wt; 
}

void
Pet::set_lives( int lives )
{
    lives_ = lives; 
} 

// class Pet, end 

///////////////////////////////////////////////////////////////////////////////////////////

// class Cat
// for cats 

class Cat : public Pet 
{
public: 
    Cat() : Pet() 
    { 
        set_age( 3 ); 
        set_weight( 15 ); 
        set_lives( 6 ); 
    }

    void set_lives( int ); 

}; 

void
Cat::set_lives( int l )
{
    lives_ = 9; 
} 

// tests to see if our classes work 

int main() {
    Pet pet; 

    std::cout << pet.get_age() << std::endl; 
    std::cout << pet.get_weight() << std::endl; 
    std::cout << pet.get_lives() << std::endl; 

    pet.set_lives( 10 ); 

    std::cout << pet.get_age() << std::endl; 
    std::cout << pet.get_weight() << std::endl; 
    std::cout << pet.get_lives() << std::endl; 

    Cat gato; 

    std::cout << gato.get_age() << std::endl; 
    std::cout << gato.get_weight() << std::endl; 
    std::cout << gato.get_lives() << std::endl; 

    gato.set_lives( 10 ); 

    std::cout << gato.get_age() << std::endl; 
    std::cout << gato.get_weight() << std::endl; 
    std::cout << gato.get_lives() << std::endl; 

    return 0; 
}
