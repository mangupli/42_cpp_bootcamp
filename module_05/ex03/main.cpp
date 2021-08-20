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

 //  newForm = vasya.makeForm("robotomy request", "whale");
//   newForm = vasya.makeForm("presidental pardon", "whale");
 //  newForm = vasya.makeForm("shrubbery creation", "whale");

   newForm = vasya.makeForm("no name like this", "whale");
   if (newForm)
    newForm->action();

   delete newForm;


    return 0;
}
