#include "HumanB.class.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
    return;
}

HumanB::~HumanB( void )
{
    return;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    return ;
}

void HumanB::attack( void ) const
{
    std::cout << this->_name << " attacks";
    if (this->_weapon != NULL)
        std::cout << " with his " << (*this->_weapon).getType() << std::endl;
    else
        std::cout << std::endl;
    return ;
}