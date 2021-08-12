#include "Dog.class.hpp"

Dog::Dog( void )
{
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
    
    this->_brain = new Brain();
    
    return;
}

Dog::Dog (Dog const & other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    
    if (other._brain)
    {
        this->_brain = new Brain(); 
        (*this->_brain) = (*other._brain);
    }

    return;
}

Dog::~Dog( void )
{
    std::cout << "Dog destructor called" << std::endl;
    
    delete this->_brain;

    return;
}

Dog & Dog::operator=(Dog const & other)
{
    std::cout << "Dog assignation operator is called" << std::endl;
    
    if (this == &other)
    {
        return (*this);
    }

    delete this->_brain;

    if (other._brain)
    {
        this->_brain = new Brain();
        this->_brain = other._brain;
    }
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

Brain * Dog::getBrain( void ) const
{
    return this->_brain;
}

