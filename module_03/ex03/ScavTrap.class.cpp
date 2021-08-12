#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"

ScavTrap::ScavTrap( void ): ClapTrap()
{
	std::cout << "ScavTrap(child) default constructor called" << std::endl;

	this->setIntAttributes(100, 50, 20);

	return;
}

ScavTrap::ScavTrap( std::string const name ): ClapTrap(name)
{
	std::cout << "ScavTrap(child) parametric constructor called" << std::endl;

	this->setIntAttributes(100, 50, 20);

	return;
}

ScavTrap::ScavTrap( ScavTrap const & other )
{
	std::cout << "ScavTrap(child) assignment operator called" << std::endl;
	*this = other;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & equalTo )
{
	std::cout << "ScavTrap(child)  assignment operator called" << std::endl;
	if ( this != &equalTo )
	{
		this->_name = equalTo._name;
		this->setIntAttributes( equalTo._hitPoints,
						 			equalTo._energyPoints,
									  	equalTo._attackDamage);
	}
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap(child) default constructor called" << std::endl;
	return;
}

void ScavTrap::guardGate( void ) const
{
	std::cout << "ScavTrap " << this->_name << " has entered in GATE KEEPER mode." << std::endl ;
	return;
}