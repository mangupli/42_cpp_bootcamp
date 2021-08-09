#include "ClapTrap.class.hpp"

ClapTrap::ClapTrap( void ): _name("Default name"), _hitPoints(100),
							_energyPoints(50), _attackDamage(20)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( std::string const name ): _name(name), _hitPoints(100),
							_energyPoints(50), _attackDamage(20)
{
	std::cout << "ClapTrap parametric constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const & src ): _name(src._name)
{
	std::cout << "ClapTrap  copy constructor called" << std::endl;
	*this = src;
	return;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & equalTo )
{
	if ( this != &equalTo )
	{
		this->_attackDamage = equalTo._attackDamage;
		this->_energyPoints = equalTo._energyPoints;
		this->_hitPoints = equalTo._hitPoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return;
}

void 	ClapTrap::printAttributes( void )
{
	std::cout<<"Attributes:" << std::endl;
	std::cout<< "Name: " << this->_name << std::endl;
	std::cout<< "Hitpoints: " << this->_hitPoints << std::endl;
	std::cout<< "Energy points: " << this->_energyPoints << std::endl;
	std::cout<< "Attack damage: " << this->_attackDamage << std::endl;
}



