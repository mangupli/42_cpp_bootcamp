#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

#include "ClapTrap.class.hpp"

class ScavTrap: public ClapTrap {

public:
		ScavTrap( void );
		ScavTrap( std::string const name );
		ScavTrap( ScavTrap const & other );
		~ScavTrap( void );

		ScavTrap & operator=( ScavTrap const & equalTo );

		void guardGate( void ) const;
};

#endif