#ifndef FLAGTRAP_CLASS_H
# define FLAGTRAP_CLASS_H

#include "ClapTrap.class.hpp"

class FlagTrap: virtual public ClapTrap {

public:
	FlagTrap( void );
	FlagTrap( std::string const name );
	FlagTrap( FlagTrap const & other );
	~FlagTrap( void );

	FlagTrap & operator=( FlagTrap const & equalTo );

	void highFivesGuys( void ) const;

};

#endif