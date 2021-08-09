#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

# include <iostream>

class ClapTrap {

private:

	std::string	const	_name;
	int					_hitPoints;
	int					_energyPoints;
	int					_attackDamage;

public:

	ClapTrap( void );
	ClapTrap( std::string const name );
	ClapTrap( ClapTrap const & src );
	~ClapTrap( void );

	ClapTrap & operator=( ClapTrap const & equalTo );

	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void 	printAttributes( void );

};

#endif