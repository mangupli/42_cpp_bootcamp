#include "Pony.class.hpp"

Pony::Pony( std::string  name, int parent) : _name(name), _parent( parent)
{
    std::cout << "New pony was born!" << std::endl;
    this->_hoursToPlayPerDay = 24;
    this->_favoriteMeal = "";
    return ;
}

Pony::~Pony(void)
{
    std::cout << "Our beautiful pony " << this->_name << " flew away to the FairyLand. Goodbye!" << std::endl;
    return ;
}

void    Pony::getName( void ) const
{
    std::cout << "It's name is " << this->_name << "." << std::endl;
    return ;
}

void    Pony::getParent( void ) const
{
    switch(this->_parent)
    {
    case STACK:
        std::cout << "It's father is Mr. Stack." << std::endl;
        break ;
    case HEAP:
        std::cout << "It's mother is Mrs. Heap." << std::endl;
        break ;
    }
    return ;
}

void    Pony::getFavoriteMeal( void ) const
{
    if (!this->_favoriteMeal.empty())
        std::cout << "Oh! It's favorite meal on Earth is " << this->_favoriteMeal << "!" << std::endl;
    else
        std::cout << "Our pony doesn't have a favorite meal yet :c You should let " << this->_name << " try something yummy!" << std::endl;
    return ;
}

void    Pony::setFavoriteMeal( std::string meal)
{
    this->_favoriteMeal = meal;
    return ;
}