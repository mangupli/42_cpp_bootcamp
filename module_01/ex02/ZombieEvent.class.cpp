#include "ZombieEvent.class.hpp"

ZombieEvent::ZombieEvent ( void ): _type("disgusting")
{
    return ;
}

ZombieEvent::~ZombieEvent ( void )
{
    return ;
}

 void ZombieEvent::setZombieType(std::string type)
 {
     this->_type = type;
     return ;
 }

 Zombie* ZombieEvent::newZombie(std::string name)
 {
     return (new Zombie(name, this->_type));
 }

 Zombie* ZombieEvent::randomChump( void )
 {
    Zombie* zombie;
    const std::string names[] = {"Boris", "Svetlana", "Galya", "Klava", "Andrey", "Vladimir", "Ivan", "Stanislav", "Marusya", "Matryona"};

    this->setZombieType("random");
    std::random_device device;
    std::uniform_int_distribution<unsigned int> gen(0, 9);
    zombie = this->newZombie(names[gen(device)]);
    (*zombie).announce();
    
    return (zombie);
 }

