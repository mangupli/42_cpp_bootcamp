#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.class.hpp"

Intern::Intern( Intern const & other )
{
    *this = other;
}

Intern & Intern::operator=( Intern const & )
{
    return (*this);
}

 Form    *Intern::makeForm(std::string nameOfForm, std::string target)
 {
     int numberOfForms = 3;
     Form *forms[numberOfForms];

    forms[0] = new ShrubberyCreationForm(target);
    forms[1] = new PresidentalPardonForm(target);
    forms[2] = new RobotomyRequestForm(target);

    std::cout << "Intern tries to find a form with name <" << nameOfForm << ">" << std::endl;
    
    Form *found = nullptr;
    int i = 0;
    
    while ( found == nullptr && i < numberOfForms)
    {
        if (nameOfForm == forms[i]->getName())
        {
            std::cout << "Found!" << std::endl;
            found = forms[i]->makeCopy();
        }
        ++i;
    }

    for(int i = 0; i < numberOfForms; ++i)
        delete forms[i];

    if (found == nullptr)
        std::cout << "There is no form with such name!" << std::endl;
    
    return (found);
 }