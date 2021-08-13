#ifndef CURE_CLASS_H
# define CURE_CLASS_H

#include "AMateria.class.hpp"

class Cure: public AMateria {

public:

	Cure( void );
	Cure( Cure const & );
	virtual ~Cure( void );

	Cure & operator=(Cure const & );

	virtual AMateria* clone( void ) const;
	virtual void use( ICharacter& target );

};


#endif