#ifndef CHARACTER_CLASS_H
# define CHARACTER_CLASS_H

# include "ICharacter.class.hpp"
# include <string>

# define MAX_EQUIP_NUM 4

class Character: public ICharacter {

private:

	Character( void );

protected:

	std::string _name;
	int 		_equipped;
	AMateria	*_inventory[MAX_EQUIP_NUM];


public:

	Character( std::string const & name );
	Character( Character const & other );
	virtual ~Character( void );

	Character & operator=( Character const & );

	virtual std::string	const & getName() const;
	virtual void		equip( AMateria* m );
	virtual void		unequip( int idx );
	virtual void		use( int idx, ICharacter& target );

};

#endif