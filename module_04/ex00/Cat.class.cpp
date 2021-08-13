#include "Cat.class.hpp"

Cat::Cat( void )
{
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
    return;
}

Cat::Cat (Cat const & other)
{
    *this = other;
    return;
}

Cat::~Cat( void )
{
    std::cout << "Cat destructor called" << std::endl;
    return;
}

Cat & Cat::operator=(Cat const & )
{
    return (*this);
}

void Cat::makeSound( void ) const
{
    std::cout << "Meow" << std::endl;
    return;
}

void Cat::iAmCat( void ) const
{
    std::cout << "I scorn you!" << std::endl;
    return;
}
