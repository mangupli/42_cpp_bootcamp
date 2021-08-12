#include "Brain.class.hpp"

Brain::Brain( void )
{
    std::cout << "Brain default constructor called" << std::endl;
   
    ideas = new std::string[100];
    for (int i = 0; i < 100; ++i)
        ideas[i] = "empty";

    return;
}

Brain::Brain (Brain const & other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    if (other.ideas)
    {
        ideas = new std::string[100];
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    return;
}

Brain::~Brain( void )
{
    std::cout << "Brain destructor called" << std::endl;

    delete[] this->ideas;
    return;
}

Brain & Brain::operator=(Brain const & other)
{
    std::cout << "Brain assignation operator is called" << std::endl;
    
    if (this == &other)
    {
       return (*this);
    }
    
    delete[] this->ideas;

    if (other.ideas)
    {
        ideas = new std::string[100];

        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    return (*this);
}