#include "Character.class.hpp"

/*
 * --------------Constructors------------
 */

Character::Character( void ):_name("Noname"), _equipped(0) {}

Character::Character( std::string const & name ):_name(name), _equipped(0)
{
	//std::cout << "Character parametric constructor called" << std::endl;

	for (int i = 0; i < MAX_EQUIP_NUM; ++i)
		this->_inventory[i] = 0;
}

Character::Character( Character const & other ):_equipped(other._equipped)
{
	//std::cout << "Character copy constructor called" << std::endl;

	for (int i = 0; i < MAX_EQUIP_NUM; ++i)
	{
		if (other._inventory[i] != 0)
			this->_inventory[i] = this->_inventory[i]->clone();
		else
			this->_inventory[i] = 0;
	}
}

/*
 * ---------------Operators--------------
 */

Character & Character::operator=( Character const & other )
{
	//std::cout << "Character assignation operator is called" << std::endl;

	if (this == &other)
		return (*this);

	this->_equipped = other._equipped;

	for (int i = 0; i < MAX_EQUIP_NUM; ++i)
		delete this->_inventory[i];

	for (int i = 0; i < MAX_EQUIP_NUM; ++i)
	{
		if (other._inventory[i] != 0)
			this->_inventory[i] = this->_inventory[i]->clone();
		else
			this->_inventory[i] = 0;
	}
	return (*this);
}

Character::~Character( void )
{
	//std::cout << "Character destructor called" << std::endl;

	for (int i = 0; i < MAX_EQUIP_NUM; ++i)
		delete this->_inventory[i];
}

/*
 * -------------Member functions--------------
 */

std::string const & Character::getName() const
{
	return(this->_name);
}

void Character::equip( AMateria* m )
{
	if (_equipped == MAX_EQUIP_NUM || m == NULL)
		return ;

	_inventory[_equipped] = m;
	++_equipped;

	return;
}

void Character::unequip( int idx )
{
	if( idx < 0 || idx > MAX_EQUIP_NUM || idx >= this->_equipped ||
						this->_inventory[idx] == 0 )
		return;

	for (int i = idx; i < (MAX_EQUIP_NUM - 1); ++i)
	{
		this->_inventory[i] = this->_inventory[i + 1];
		this->_inventory[i + 1] = 0;
	}

	return;
}

void Character::use(int idx, ICharacter& target)
{
	if( idx < 0 || idx > MAX_EQUIP_NUM || idx >= this->_equipped ||
											this->_inventory[idx] == 0 )
		return;

	_inventory[idx]->use(target);

	return;
}


