#ifndef ZOMBIEEVENT_CLASS_H
#define ZOMBIEEVENT_CLASS_H

#include "Zombie.class.hpp"

class ZombieEvent
{
public:

    ZombieEvent( void );
    ~ZombieEvent (void );

    void setZombieType(std::string type);
    Zombie* newZombie(std::string name);
    Zombie* randomChump( void );

private:
    std::string _type;
};


#endif