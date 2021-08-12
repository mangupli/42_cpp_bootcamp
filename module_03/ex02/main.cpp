#include "FlagTrap.class.hpp"
#include "FlagTrap.class.hpp"
#include "ClapTrap.class.hpp"

int main()
{

	ClapTrap claptrap("Clappie");
	FlagTrap flagtrap("Flaggie");


	claptrap.printAttributes();
	flagtrap.printAttributes();

	claptrap.attack("TARGET");
	flagtrap.attack("TARGET");

	std::cout << std::endl;

	claptrap.takeDamage(99);
	std::cout << "Claptrap hit points: " << claptrap.getHitPoints()
	<< std::endl << std::endl;

	flagtrap.takeDamage(99);
	std::cout << "FlagTrap hit points: " << flagtrap.getHitPoints()
	<< std::endl << std::endl;

	flagtrap.highFivesGuys();

	std::cout << std::endl;

	FlagTrap duplicate;
	flagtrap = duplicate;

	flagtrap.printAttributes();

	return 0;
}
