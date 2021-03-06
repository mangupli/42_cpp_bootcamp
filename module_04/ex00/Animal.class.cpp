#include "Animal.class.hpp"

Animal::Animal( void ): _type("NoType")
{
    std::cout << "Animal default constructor called" << std::endl;
    return;
}

Animal::Animal (Animal const & other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
    return;
}

Animal::~Animal( void )
{
    std::cout << "Animal destructor called" << std::endl;
    return;
}

Animal & Animal::operator=(Animal const & )
{
    return (*this);
}

std::string Animal::getType( void ) const
{
    return (this->_type);
}

void Animal::makeSound( void ) const
{
    std::cout << "???" << std::endl;
    return;
}

