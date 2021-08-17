#include "AMateria.class.hpp"

/*
 * --------------Constructors------------
 */

AMateria::AMateria( std::string const &type ): _type(type) {}

AMateria::AMateria( AMateria const & other )
{
	*this = other;
}

/*
 * ---------------Operators--------------
 */

AMateria & AMateria::operator=( AMateria const & other )
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

/*
 * -------------Member functions--------------
 */

std::string const & AMateria::getType( void ) const
{
	return (this->_type);
}

void AMateria::use( ICharacter& target )
{
	(void)target;
}
