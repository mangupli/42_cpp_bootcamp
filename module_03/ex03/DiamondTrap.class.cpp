#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include "FlagTrap.class.hpp"
#include "DiamondTrap.class.hpp"

DiamondTrap::DiamondTrap( void ): ClapTrap("Default_name_clap_name"),
								ScavTrap(), FlagTrap(), _name("Default_name")

{
	std::cout << "DiamondTrap(child) default constructor called" << std::endl;
	this->setIntAttributes(100, 50, 30);

	return;
}

DiamondTrap::DiamondTrap( std::string const name ): ClapTrap(name + "_clap_name"),
								ScavTrap(name), FlagTrap(name), _name(name)
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
	std::cout << "----------" << std::endl;
	std::cout << "Who Am I?" << std::endl
	<< "I am DiamondTrap and my name is: " << this->_name << std::endl;
	std::cout << "My Claptrap name is: " << ClapTrap::getName() << std::endl;
	std::cout << "----------" << std::endl;
	return;
}

std::string DiamondTrap::getName() const
{
	return this->_name;
}

void			DiamondTrap::setName( std::string const name )
{
	this->_name = name;
}

