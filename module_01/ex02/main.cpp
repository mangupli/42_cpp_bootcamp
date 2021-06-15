#include "Zombie.class.hpp"
#include "ZombieEvent.class.hpp"

int main()
{
    ZombieEvent zEvent;
    
    Zombie newZombie("Richard", "deadman");
    newZombie.announce();

    Zombie *newZombiePtr;
    newZombiePtr = zEvent.newZombie("Georg");
    (*newZombiePtr).announce();
    delete newZombiePtr;

    zEvent.setZombieType("Green crazy dude");
    newZombiePtr = zEvent.newZombie("Martin");
    (*newZombiePtr).announce();
    delete newZombiePtr;

    newZombiePtr = zEvent.randomChump();
    delete newZombiePtr;
    
    return 0;
}
