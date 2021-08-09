#include "ClapTrap.class.hpp"
#include "FlagTrap.class.hpp"

FlagTrap::FlagTrap( void )
{
	std::cout << "FlagTrap default constructor called" << std::endl;
	//присвоить поля

	return;
}

FlagTrap::FlagTrap( std::string const name ): ClapTrap(name)
{
	std::cout << "FlagTrap parametric constructor called" << std::endl;

	//присвоить поля

	return;
}



FlagTrap::~FlagTrap( void )
{
	std::cout << "FlagTrap default constructor called" << std::endl;
	return;
}