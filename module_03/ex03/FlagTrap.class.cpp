#include "ClapTrap.class.hpp"
#include "FlagTrap.class.hpp"

FlagTrap::FlagTrap( void ): ClapTrap()
{
	std::cout << "FlagTrap(child) default constructor called" << std::endl;
	this->setIntAttributes(100, 100, 30);

	return;
}

FlagTrap::FlagTrap( std::string const name ): ClapTrap(name)
{
	std::cout << "FlagTrap(child) parametric constructor called" << std::endl;

	this->setIntAttributes(100, 100, 30);

	return;
}

FlagTrap::FlagTrap( FlagTrap const & other )
{
	std::cout << "FlagTrap(child) assignment operator called" << std::endl;
	*this = other;
}

FlagTrap & FlagTrap::operator=( FlagTrap const & equalTo )
{
	std::cout << "FlagTrap(child)  assignment operator called" << std::endl;
	if ( this != &equalTo )
	{
		this->_name = equalTo._name;
		this->setIntAttributes( equalTo._hitPoints,
									equalTo._energyPoints,
										equalTo._attackDamage);
	}
	return (*this);
}

FlagTrap::~FlagTrap( void )
{
	std::cout << "FlagTrap(child) default constructor called" << std::endl;
	return;
}

void FlagTrap::highFivesGuys( void ) const
{
	std::cout << "FlagTrap " << this->_name << " screams:" << std::endl;
	for(int i = 0; i < 5; i++)
		std::cout << "HIGH FIVE!" << std::endl;
	return;
}
