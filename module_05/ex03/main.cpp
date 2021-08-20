#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.class.hpp"

int main()
{
   Intern vasya;
   Form *newForm;

   std::string arrayOfNames[4] = {
        "srubbery cration",     //[0]
        "robotomy request",     //[1]
        "presidential pardon",  //[2]
        "no name like this"     //[3]
    }; 

    for (int i = 0; i < 4; ++i)
    {
        newForm = vasya.makeForm(arrayOfNames[i], "Bulka");
        if (newForm)
          newForm->action();
          
        delete newForm;

        std::cout << std::endl;
    }

    return 0;
}
