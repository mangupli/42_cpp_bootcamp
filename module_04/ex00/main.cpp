#include "Animal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;

   // i->iAmCat(); // Animal points at Cat type class
                    //but it's still Animal and doesn't see
                    //Cat member functions

    delete i;
    delete j;
    delete meta;

    return 0;
}