#include "AAnimal.class.hpp"

AAnimal::AAnimal( void ): _type("NoType")
{
    std::cout << "AAnimal default constructor called" << std::endl;
    return;
}

AAnimal::AAnimal (AAnimal const & other)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = other;
    return;
}

AAnimal::~AAnimal( void )
{
    std::cout << "AAnimal destructor called" << std::endl;
    return;
}

AAnimal & AAnimal::operator=(AAnimal const & )
{
    return (*this);
}

std::string AAnimal::getType( void ) const
{
    return (this->_type);
}
