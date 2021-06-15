#include "Zombie.class.hpp"

Zombie::Zombie( std::string name, std::string type ) : _name(name), _type(type)
{
    std::cout  << std::endl << "Haha! Zombie Apocalypse is coming! The new one was born!" << std::endl;
    return;
}

Zombie::~Zombie( void )
{
     std::cout << "Oh no! " << this->_name << " was killed!" << std::endl;
    return ;
}

std::string Zombie::getName( void ) const
{
    return (this->_name);
}

std::string Zombie::getType( void ) const
{
    return (this->_type);
}

void Zombie::announce( void ) const
{
    std::cout << "<" << this->_name << " (" << this->_type << ")> Braaaaiiinssss...!" << std::endl;
    return ;
}