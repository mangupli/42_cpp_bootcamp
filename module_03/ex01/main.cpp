#include "FlagTrap.class.hpp"
#include "ClapTrap.class.hpp"

int main()
{

	FlagTrap instance;


	instance.printAttributes();


	instance.attack("sir White");
	instance.takeDamage(99);
	std::cout << "hit points: " << instance.getHitPoints() << std::endl << std::endl;

	instance.takeDamage(99);
	std::cout << "hit points: " << instance.getHitPoints() << std::endl << std::endl;

	instance.takeDamage(99);
	std::cout << "hit points: " << instance.getHitPoints() << std::endl << std::endl;

	instance.beRepaired(2);
	std::cout << "hit points: " << instance.getHitPoints() << std::endl << std::endl;

	instance.beRepaired(40);
	std::cout << "hit points: " << instance.getHitPoints() << std::endl << std::endl;

	return 0;
}
