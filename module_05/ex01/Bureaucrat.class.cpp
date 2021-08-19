#include "Bureaucrat.class.hpp"

/*
*-------Constructors--------
*/

Bureaucrat::Bureaucrat( void ):
                        _name("NoName"), _grade(0) {}


Bureaucrat::Bureaucrat(std::string name, int grade):
                                    _name(name), _grade(0)
{
    std::cout << "Trying to create new Bureaucrat <" << name << ">..." << std::endl;
    this->setGrade(grade);
    std::cout << "Done!" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & other):
                                    _name(other._name)
{
    this->_grade = other._grade;
}


Bureaucrat::~Bureaucrat( void )
{
    std::cout << "Bureaucrat destroyed!" << std::endl;
}

/*
* ------ Operators--------
*/

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & other)
{
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

std::ostream &	operator<<(std::ostream & out, Bureaucrat const & b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
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
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->_grade = grade;
}

/*
*------ Member functions ------
*/

void    Bureaucrat::plusGrade( void )
{
   this->setGrade(this->_grade - 1);
}

void    Bureaucrat::minusGrade( void )
{
    this->setGrade(this->_grade + 1);
}

void    Bureaucrat::signForm( Form & form )
{
    try
    {
        form.beSigned(*this);
        std::cout << "Bureaucrat <" << this->_name << "> signed the form <"
        << form.getName() << ">" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Bureaucrat <" << this->_name << "> cannot sign the form <"
        << form.getName() << "> because ";
        std::cout << e.what() << '\n';
    }
    
}
