#include "AAnimal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"
#include "Brain.class.hpp"


int main()
{
    // AAnimal animal; // not ok because it's an Abstract class

    const AAnimal* j = new Dog(); //ok
    const AAnimal* i = new Cat(); //ok

    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    // meta->makeSound(); //not ok

    std::cout << std::endl;

    delete i;
    delete j;


    return 0;
}