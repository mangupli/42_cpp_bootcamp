#include "Cat.class.hpp"

Cat::Cat( void )
{
    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
    
    this->_brain = new Brain();
    
    return;
}

Cat::Cat (Cat const & other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    
    if (other._brain)
    {
        this->_brain = new Brain(); 
        (*this->_brain) = (*other._brain);
    }

    return;
}

Cat::~Cat( void )
{
    std::cout << "Cat destructor called" << std::endl;
    
    delete this->_brain;

    return;
}

Cat & Cat::operator=(Cat const & other)
{
    std::cout << "Cat assignation operator is called" << std::endl;
    
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
