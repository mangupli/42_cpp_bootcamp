#ifndef ICE_CLASS_H
# define ICE_CLASS_H

#include "AMateria.class.hpp"

class Ice: public AMateria {

public:

	Ice( void );
	Ice( Ice const & );
	virtual ~Ice( void );

	Ice & operator=( Ice const & );

	virtual AMateria* clone( void ) const;
	virtual void use( ICharacter& target );

};


#endif