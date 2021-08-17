#include "Bureaucrat.class.hpp"

void boundaryTesting( void );
void changingGradeTesting( void );

int main()
{
    boundaryTesting();
    changingGradeTesting();

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
         Bureaucrat b("Name", grade);
         std::cout << b << std::endl;
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
         Bureaucrat b("Name", grade);
         std::cout << b << std::endl;
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
         Bureaucrat b("Name", grade);
         std::cout << b << std::endl;
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
         Bureaucrat b("Name", grade);
         std::cout << b << std::endl;
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
         Bureaucrat b("Name", grade);
         std::cout << b << std::endl;
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
         Bureaucrat b("Name", grade);
         std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

}

void changingGradeTesting( void )
{
   std::cout << std::endl << "Testing increment/decrement of the grade:"
    << std::endl << std::endl;
   
    try
    {
       Bureaucrat newbie("Newbie", 150);
       std::cout << newbie << std::endl;

       
       std::cout<< "incrementing grade..." << std::endl;
       newbie.plusGrade();
       std::cout<< "new grade:" << newbie.getGrade() << std::endl;

       std::cout<< "decrementing grade..." << std::endl;
       newbie.minusGrade();
       std::cout<< "new grade:" << newbie.getGrade() << std::endl;

       std::cout<< "decrementing grade..." << std::endl;
       newbie.minusGrade();
       std::cout<< "new grade:" << newbie.getGrade() << std::endl;
       
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;
    

    try
    {

       Bureaucrat master("Master B", 3);
       std::cout << master << std::endl;

       
       std::cout<< "incrementing grade..." << std::endl;
       master.plusGrade();
       std::cout<< "new grade:" << master.getGrade() << std::endl;
       
       for (int i = 0; i < 4; ++i)
       {
           std::cout<< "incrementing grade..." << std::endl;
           master.plusGrade();
           std::cout<< "new grade:" << master.getGrade() << std::endl;
        }
       
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;

}