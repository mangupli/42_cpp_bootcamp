#include "Cure.class.hpp"

/*
 * --------------Constructors------------
 */

Cure::Cure( void ): AMateria("cure")
{
	//std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure( void )
{
	//std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure( Cure const & ): AMateria("cure")
{
	//std::cout << "Cure copy destructor called" << std::endl;
}

/*
 * ---------------Operators--------------
 */

Cure & Cure::operator=( Cure const & )
{
	//std::cout << "Cure assignation operator destructor called" << std::endl;

	return (*this);
}

/*
 * -------------Member functions--------------
 */

void Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return;
}

AMateria* Cure::clone( void ) const
{
	return (new Cure(*this));
}