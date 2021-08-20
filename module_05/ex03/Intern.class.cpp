#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.class.hpp"

typedef Form    *(Intern:: * funcPtr)(std::string);

Intern::Intern( Intern const & other )
{
    *this = other;
}

Intern & Intern::operator=( Intern const & )
{
    return (*this);
}

Form    *Intern::makeShrubCreatForm( std::string target )
{
    return new ShrubberyCreationForm(target);
}

Form    *Intern::makePresPardForm( std::string target )
{
    return new PresidentalPardonForm(target);
}

Form    *Intern::makeRobReqForm( std::string target )
{
    return new RobotomyRequestForm(target);
}

Form    *Intern::makeForm(std::string nameOfForm, std::string target)
{
    
    std::string arrayOfNames[FORMSNUM] = {
        "srubbery cration",     //[0]
        "robotomy request",     //[1]
        "presidential pardon"  //[2]
    }; 

    (void)nameOfForm;

    funcPtr arrayOfFunctions[FORMSNUM] = {
        &Intern::makeShrubCreatForm,    //[0]
        &Intern::makeRobReqForm,        //[1]
        &Intern::makePresPardForm        //[2]
    };

    std::cout << "Intern tries to find a form with name <" << nameOfForm << ">" << std::endl;
    
    for (int i = 0; i < FORMSNUM; ++i)
    {
        if (arrayOfNames[i] == nameOfForm)
        {
            std::cout << "Found!" << std::endl;
            return (this->*(arrayOfFunctions[i]))(target);
        }
    }

    std::cout << "There is no form with such name!" << std::endl;
    
    return (nullptr);

}
