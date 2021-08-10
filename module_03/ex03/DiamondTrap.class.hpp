#ifndef DIAMONDTRAP_CLASS_H
# define DIAMONDTRAP_CLASS_H

#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include "FlagTrap.class.hpp"

class DiamondTrap: public ScavTrap, public FlagTrap {

private:
	std::string _name;

public:
	DiamondTrap( void );
	DiamondTrap( std::string const name );
	DiamondTrap( DiamondTrap const & other );
	~DiamondTrap( void );

	DiamondTrap & operator=( DiamondTrap const & equalTo );

	void whoAmI( void ) const;

};

#endif