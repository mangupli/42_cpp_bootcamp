#ifndef AMATERIA_CLASS_H
# define AMATERIA_CLASS_H

# include <string>
# include <iostream>

# include "ICharacter.class.hpp"

class ICharacter;

class AMateria
{
protected:

	std::string _type;

	AMateria( void ) {}

public:

	AMateria( std::string const & type );
	AMateria( AMateria const & other );
	virtual ~AMateria( void ) {}

	AMateria & operator=( AMateria const & other );

	std::string const & getType( void ) const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use( ICharacter& target );

};

#endif