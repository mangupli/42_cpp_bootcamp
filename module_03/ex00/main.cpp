#include "ClapTrap.class.hpp"

int main()
{

	ClapTrap instance;
	ClapTrap Denis("Denis");

	instance.printAttributes();

	Denis = instance;
	Denis.printAttributes();

	Denis.attack("sir White");
	Denis.takeDamage(99);
	std::cout << "hit points: " << Denis.getHitPoints() << std::endl << std::endl;

	Denis.takeDamage(99);
	std::cout << "hit points: " << Denis.getHitPoints() << std::endl << std::endl;

	Denis.takeDamage(99);
	std::cout << "hit points: " << Denis.getHitPoints() << std::endl << std::endl;

	Denis.beRepaired(2);
	std::cout << "hit points: " << Denis.getHitPoints() << std::endl << std::endl;

	Denis.beRepaired(40);
	std::cout << "hit points: " << Denis.getHitPoints() << std::endl << std::endl;

	return 0;
}
