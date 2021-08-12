#include "ClapTrap.class.hpp"

/*
 * ---------- Constructors ------------
 */


ClapTrap::ClapTrap( void ): _name("Default name"), _hitPoints(10),
							_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap(parent) default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( std::string const name ): _name(name), _hitPoints(10),
							_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap(parent) parametric constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const & other )
{
	std::cout << "ClapTrap(parent) copy constructor called" << std::endl;
	*this = other;
	return;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & equalTo )
{
	std::cout << "ClapTrap(parent) assignment operator called" << std::endl;
	if ( this != &equalTo )
	{
		this->_name = equalTo._name;
		this->_attackDamage = equalTo._attackDamage;
		this->_energyPoints = equalTo._energyPoints;
		this->_hitPoints = equalTo._hitPoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap(parent) destructor called" << std::endl;
	return;
}

/*
 * ------------- Methods ----------------
 */

void ClapTrap::printAttributes( void )
{
	std::cout << std::endl << "***" << std::endl;
	std::cout<< "Attributes of '" << this->_name << "': " << std::endl;
	std::cout<< "Hitpoints: " << this->_hitPoints << std::endl;
	std::cout<< "Energy points: " << this->_energyPoints << std::endl;
	std::cout<< "Attack damage: " << this->_attackDamage << std::endl;
	std::cout << "***" << std::endl << std::endl;
}

void ClapTrap::attack(const std::string &target) const
{
	std::cout << "ClapTrap " << this->_name << " attacks " << target
	<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	return;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
		<< " can't take any more damage! Hit points = 0" << std::endl;
	}
	else if (this->_hitPoints - amount < this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << " has been under attack "
				  << ", causing " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has been under attack "
				  << ", causing " << amount << " points of damage! ";
		std::cout << "<Now it has no more hit points>" << std::endl;
		this->_hitPoints = 0;
	}
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " has been repaired by "
	<< amount << " points!" << std::endl ;
	this->_hitPoints += amount;
	return;
}

/*
 * --------------- Getters -----------
 */

unsigned int ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

std::string ClapTrap::getName() const
{
	return this->_name;
}

/*
 * --------------- Setters -----------
 */

void			ClapTrap::setName( std::string const name )
{
	this->_name = name;
}

void			ClapTrap::setHitPoints( unsigned int hitPoints )
{
	this->_hitPoints = hitPoints;
}

void			ClapTrap::setEnergyPoints( unsigned int energyPoints )
{
	this->_energyPoints = energyPoints;
}

void			ClapTrap::setAttackDamage( unsigned int attackDamage )
{
	this->_attackDamage = attackDamage;
}
