#include "ZombieHorde.class.hpp"

ZombieHorde::ZombieHorde ( unsigned int numberOfZombies ): _type("virus affected zombie")
{
    this->zombies = new Zombie[numberOfZombies];
    this->_numberOfZombies = numberOfZombies;

    for (unsigned int i = 0; i < numberOfZombies; i++)
    {
        this->zombies[i].setType(_type);
        this->zombies[i].setName(this->randomName());
    }

    return ;
}

ZombieHorde::~ZombieHorde ( void )
{
    delete[] this->zombies;
    return ;
}

void ZombieHorde::setZombieType(std::string type)
{
     this->_type = type;
     return ;
}

void ZombieHorde::announce( void ) const
{
    for(unsigned int i = 0; i < this->_numberOfZombies; i++)
    {
        this->zombies[i].announce();
    }
    return ;
}

std::string ZombieHorde::randomName( void ) const
{
    const std::string names[] = {"Boris", "Svetlana", "Galya", "Klava", "Andrey", "Vladimir", "Ivan", "Stanislav", "Marusya", "Matryona"};

    std::random_device device;
    std::uniform_int_distribution<unsigned int> gen(0, 9);
    return (names[gen(device)]);
}
