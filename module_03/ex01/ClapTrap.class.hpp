#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

# include <iostream>

class ClapTrap {

protected:

	std::string			_name;
	unsigned int		_hitPoints;
	unsigned int		_energyPoints;
	unsigned int		_attackDamage;

public:

	ClapTrap( void );
	ClapTrap( std::string const name );
	ClapTrap( ClapTrap const & other );
	~ClapTrap( void );

	ClapTrap & operator=( ClapTrap const & equalTo );

	void			attack(std::string const & target) const;
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	void			printAttributes( void );

	std::string		getName( void ) const;
	unsigned int	getHitPoints( void ) const;
	unsigned int	getEnergyPoints( void ) const;
	unsigned int	getAttackDamage( void ) const;

	void			setName( std::string const name );
	void			setHitPoints( unsigned int hitPoints );
	void			setEnergyPoints( unsigned int energyPoints );
	void			setAttackDamage( unsigned int attackDamage );

};

#endif
