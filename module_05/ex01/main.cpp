#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

void boundaryTesting( void );
void signingFormTesting( void );

int main()
{
    boundaryTesting();

    std::cout << "---------------------" << std::endl;

    signingFormTesting();

    return 0;
}


/*
* Trying to create different instances of the Bureaucrat class
* on the boundaries of grade variable
*/

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