#include "ScavTrap.class.hpp"
#include "ClapTrap.class.hpp"

int main()
{

	ClapTrap claptrap("Clappie");
	ScavTrap scavtrap("Scavvie");


	claptrap.printAttributes();
	scavtrap.printAttributes();

	claptrap.attack("TARGET");
	scavtrap.attack("TARGET");

	std::cout << std::endl;

	claptrap.takeDamage(99);
	std::cout << "Claptrap hit points: " << claptrap.getHitPoints() << std::endl << std::endl;

	scavtrap.takeDamage(99);
	std::cout << "ScavTrap hit points: " << scavtrap.getHitPoints() << std::endl << std::endl;

	scavtrap.guardGate();

	std::cout << std::endl;

	ScavTrap duplicate;
	scavtrap = duplicate;


	return 0;
}
