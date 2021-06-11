#include "Pony.class.hpp"

void ponyOnTheStack( void )
{
    Pony pony("Alicia", STACK);

    pony.getName();
    pony.getParent();
    pony.getFavoriteMeal();
    pony.setFavoriteMeal("cactus");
    pony.getFavoriteMeal();
    
}

void ponyOnTheHeap( void )
{
    Pony *pony = new Pony("Jack", HEAP);

    pony->getName();
    pony->getParent();
    pony->getFavoriteMeal();
    pony->setFavoriteMeal("blanket");
    pony->getFavoriteMeal();

    delete pony;
}

int main()
{
    std::cout << "***Calling Pony on The Heap**" << std::endl << std::endl;
    ponyOnTheHeap();
    std::cout << std::endl;
    
    std::cout << "***Calling Pony on The Stack***" << std::endl << std::endl;
    ponyOnTheStack();
    std::cout << std::endl;
    
    return (0);
}