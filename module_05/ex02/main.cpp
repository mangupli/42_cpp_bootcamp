#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
   ShrubberyCreationForm bushes("Forest");
   PresidentalPardonForm pardon("Milashka");
   RobotomyRequestForm robot("Kot");

   std::cout << std::endl;
   std::cout << bushes << std::endl;
   std::cout << pardon << std::endl;
   std::cout << robot << std::endl;
   std::cout << std::endl;

   Bureaucrat Vasya("Vasya", 150);
   Bureaucrat Nikolay("Kolya", 45);
   Bureaucrat Snezhinka("Snezhok", 1);

  
   std::cout << Vasya << std::endl;
   std::cout << Nikolay << std::endl;
   std::cout << Snezhinka << std::endl;

   std::cout << std::endl;

   Vasya.signForm(bushes); // grade too low -- exception
   Nikolay.signForm(bushes); // ok
   Snezhinka.signForm(bushes); // already signed -- expetion

   Vasya.executeForm(bushes);       //  grade too low -- exception
   Snezhinka.executeForm(bushes);   // ok

   std::cout << std::endl;

   Snezhinka.executeForm(pardon);     // not signed yet -- exception
   Snezhinka.signForm(pardon);        // ok
   Snezhinka.executeForm(pardon);     // ok

   std::cout << std::endl;

   Nikolay.signForm(robot);       //ok
   Nikolay.executeForm(robot);    //ok

   std::cout << std::endl;

    return 0;
}
