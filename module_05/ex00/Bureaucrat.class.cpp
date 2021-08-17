#include "Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade):
_name(name)
{

}

/*
*-------Getters--------
*/

std::string Bureaucrat::getName( void ) const
{
    return this->_name;
}

int Bureaucrat::getGrade( void ) const
{
    return this->_grade;
}


/*
*-------Setters--------
*/

void Bureaucrat::setGrade( int const grade )
{
    if (grade < 1)
        throw GradeTooLowException();
    if (grade > 150)
        throw GradeTooHighException
}

