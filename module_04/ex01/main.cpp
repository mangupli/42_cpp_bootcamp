#include "Animal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"

int main()
{
//----------Main from the subject----------------------

     const Animal* j = new Dog();
     const Animal* i = new Cat();

     std::cout << std::endl;

     delete j;//should not create a leak
     delete i;

     std::cout << std::endl;

//------------Test from the subject--------------------

    int numberOfAnimals = 4;
    Animal *arrayOfAnimals[numberOfAnimals];

//---------creating---------

    int iii = 0;
    while(iii < numberOfAnimals/2)
    {
        std::cout <<  iii << std::endl;
        arrayOfAnimals[iii] = new Dog();
        ++iii;
    }

    std::cout << std::endl;

    while(iii < numberOfAnimals)
    {
        std::cout <<  iii << std::endl;
        arrayOfAnimals[iii] = new Cat();
        ++iii;
    }

    std::cout << std::endl;


//------------deleting----------

    iii = 0;
    while(iii < numberOfAnimals)
    {
        delete arrayOfAnimals[iii];
        ++iii;
    }

    std::cout << std::endl;


//-----------Test of deep copying---------------------

     Dog Hatiko;

     std::cout << std::endl;

     Hatiko.getBrain()->ideas[0] = "FOOD!";

     std::cout << "Hatiko ideas:" << std::endl;

     std::cout <<  Hatiko.getBrain()->ideas[0] << std::endl;
     std::cout <<  Hatiko.getBrain()->ideas[1] << std::endl;

     std::cout << std::endl;
  
     Dog Muftar(Hatiko);

     std::cout << std::endl;

     std::cout << "Muftar ideas:" << std::endl;
     std::cout <<  Muftar.getBrain()->ideas[0] << std::endl;
     std::cout <<  Muftar.getBrain()->ideas[1] << std::endl;
    
     std::cout << std::endl;

    return 0;

}