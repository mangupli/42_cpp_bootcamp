#include "RobotomyRequestForm.hpp"

/*
*--------Constructors --------
*/

RobotomyRequestForm::RobotomyRequestForm( void ):
                    Form( "robotomy request", 72, 45),
                    _target("noTarget")
{
    std::cout << "RobotomyRequestForm default constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ):
                    Form("robotomy request", 72, 45),
                    _target(target)
{
    std::cout << "RobotomyRequestForm created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & other ):
                    Form("robotomy request", 72, 45),
                    _target(other._target)
{
    std::cout << "RobotomyRequestForm copy constructor called!" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & other)
{
    if (this != &other)
        this->_target = other._target;
    return *this;
}

/*
*----------Member functions------------
*/

std::string RobotomyRequestForm::getTarget( void ) const
{
    return this->_target;
}

void        RobotomyRequestForm::setTarget( std::string target )
{
    this->_target = target;
}

Form        *RobotomyRequestForm::makeCopy( void ) const
{
    return (new RobotomyRequestForm(this->_target));
}

void        RobotomyRequestForm::action ( void ) const
{
    srand (time(NULL));
    int randomNumber = rand();

    std::cout << "*** drilling noises ***" << std::endl;
	
	if ((randomNumber % 2))
		std::cout << this->_target << " has been robotomized successfully." << std::endl << std::endl;
	else
		std::cout << "Failed to robotomize " << this->_target << std::endl << std::endl;
}