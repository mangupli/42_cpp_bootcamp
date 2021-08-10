#include "ScavTrap.class.hpp"
#include "FlagTrap.class.hpp"
#include "ClapTrap.class.hpp"
#include "DiamondTrap.class.hpp"

int main()
{

	DiamondTrap diamond("Almaz");
	FlagTrap flag("Flag");
	ScavTrap scav("Scav");

	diamond.printAttributes();
	flag.printAttributes();
	scav.printAttributes();





	return 0;
}
