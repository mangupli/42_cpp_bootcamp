#include "ScavTrap.class.hpp"
#include "FlagTrap.class.hpp"
#include "ClapTrap.class.hpp"
#include "DiamondTrap.class.hpp"

int main()
{

	DiamondTrap diamond("Almaz");
	FlagTrap flag("Flag");
	ScavTrap scav("Scav");

//	diamond.printAttributes();
//	flag.printAttributes();
//	scav.printAttributes();

	std::cout << std::endl;

	diamond.whoAmI();

	diamond.printAttributes();
	std::cout << std::endl;

	diamond.guardGate();
	std::cout << std::endl;

	diamond.highFivesGuys();
	std::cout << std::endl;

	diamond.attack("TARGET");
	std::cout << std::endl;

	diamond.takeDamage(42);
	std::cout << std::endl;

	diamond.beRepaired(21);
	std::cout << std::endl;




	return 0;
}
