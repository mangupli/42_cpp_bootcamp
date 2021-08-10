#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include "FlagTrap.class.hpp"
#include "DiamondTrap.class.hpp"

DiamondTrap::DiamondTrap( void ): ScavTrap(), FlagTrap(), ClapTrap()
{
	std::cout << "DiamondTrap(child) default constructor called" << std::endl;
	this->setIntAttributes(100, 50, 30);

	return;
}

DiamondTrap::DiamondTrap( std::string const name ): FlagTrap(name), ScavTrap(name), ClapTrap(name)
{
	std::cout << "DiamondTrap(child) parametric constructor called" << std::endl;

	this->setIntAttributes(100, 50, 30);

	return;
}

DiamondTrap::DiamondTrap( DiamondTrap const & other )
{
	std::cout << "DiamondTrap(child) assignment operator called" << std::endl;
	*this = other;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & equalTo )
{
	std::cout << "DiamondTrap(child)  assignment operator called" << std::endl;
	if ( this != &equalTo )
	{
		this->_name = equalTo._name;
		this->setIntAttributes( equalTo._hitPoints,
								equalTo._energyPoints,
								equalTo._attackDamage);
	}
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap(child) default constructor called" << std::endl;
	return;
}

void DiamondTrap::whoAmI ( void ) const
{

	return;
}
