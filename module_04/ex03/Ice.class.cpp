#include "Ice.class.hpp"

/*
 * --------------Constructors------------
 */

Ice::Ice( void ): AMateria("ice")
{
	//std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice( void )
{
	//std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice( Ice const & ): AMateria("ice")
{
	//std::cout << "Ice copy destructor called" << std::endl;
}

/*
 * ---------------Operators--------------
 */

Ice & Ice::operator=( Ice const & )
{
	//std::cout << "Ice assignation operator destructor called" << std::endl;
	return (*this);
}

/*
 * -------------Member functions--------------
 */

void Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;
}

AMateria* Ice::clone( void ) const
{
	return (new Ice(*this));
}