#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void boundaryTesting( void );
void signingFormTesting( void );

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


/*
* Trying to create different instances of the Form class
* on the boundaries of grade variable
*/

/*
void boundaryTesting( void )
{
   
   std::cout << std::endl << "Boundary testing:" << std::endl << std::endl;

   try
    {
         int grade = -1;
         std::cout << "Grade: " << grade << std::endl;
         Form form("Name", grade, grade);
         std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << '\n';
    }

   std::cout << std::endl;

   try
    {
         int grade = 0;
         std::cout << "Grade: " << grade << std::endl;
         Form form("Name", grade, grade);
         std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;

    try
    {
         int grade = 1;
         std::cout << "Grade: " << grade << std::endl;
         Form form("Name", grade, grade);
         std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
         int grade = 149;
         std::cout << "Grade: " << grade << std::endl;
         Form form("Name", grade, grade);
         std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;

    try
    {
         int grade = 150;
         std::cout << "Grade: " << grade << std::endl;
         Form form("Name", grade, grade);
         std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
         int grade = 151;
         std::cout << "Grade: " << grade << std::endl;
         Form form("Name", grade, grade);
         std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

}

void signingFormTesting( void )
{
   std::cout << std::endl << "Signing form testing:" << std::endl << std::endl;
   
   Form super("SuperForm", 125, 125);
   std::cout << super << std::endl;

   Bureaucrat vasya("Vasya", 126);
   std::cout << vasya << std::endl;

   vasya.signForm(super);
   std::cout << super << std::endl;

   std::cout << std::endl;

   std::cout << "Incrementing level..." << std::endl;
   vasya.plusGrade();

   vasya.signForm(super);
   std::cout << super << std::endl;

   vasya.signForm(super);
   std::cout << super << std::endl;

}
*/