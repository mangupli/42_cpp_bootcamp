#include "Dog.class.hpp"

Dog::Dog( void )
{
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
    return;
}

Dog::Dog (Dog const & other)
{
    *this = other;
    return;
}

Dog::~Dog( void )
{
    std::cout << "Dog destructor called" << std::endl;
    return;
}

Dog & Dog::operator=(Dog const & )
{
    return (*this);
}

void Dog::makeSound( void ) const
{
    std::cout << "Woof!" << std::endl;
    return;
}

void Dog::iAmDog( void ) const
{
    std::cout << "I love you!" << std::endl;
    return;
}

