#ifndef ZOMBIEHORDE_CLASS_H
#define ZOMBIEHORDE_CLASS_H

#include "Zombie.class.hpp"
#include <random>

class ZombieHorde
{
public:

    ZombieHorde( unsigned int n );
    ~ZombieHorde (void );

    Zombie *zombies;

    std::string randomName( void ) const;
    void        setZombieType(std::string type);
    void        announce( void ) const;

private:

    std::string         _type;
    unsigned int  _numberOfZombies;

};

#endif