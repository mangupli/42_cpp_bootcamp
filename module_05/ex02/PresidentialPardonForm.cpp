#include "PresidentialPardonForm.hpp"

/*
*--------Constructors --------
*/

PresidentalPardonForm::PresidentalPardonForm( void ):
                    Form( "PresidentalPardonForm", 25, 5),
                    _target("noTarget")
{
    std::cout << "PresidentalPardonForm default constructor called!" << std::endl;
}

PresidentalPardonForm::PresidentalPardonForm( std::string target ):
                    Form("PresidentalPardonForm", 25, 5),
                    _target(target)
{
    std::cout << "PresidentalPardonForm created!" << std::endl;
}

PresidentalPardonForm::PresidentalPardonForm( PresidentalPardonForm const & other ):
                    Form("PresidentalPardonForm", 25, 5),
                    _target(other._target)
{
    std::cout << "PresidentalPardonForm copy constructor called!" << std::endl;
}

PresidentalPardonForm & PresidentalPardonForm::operator=( PresidentalPardonForm const & other)
{
    if (this != &other)
        this->_target = other._target;
    return *this;
}

/*
*----------Member functions------------
*/

std::string PresidentalPardonForm::getTarget( void ) const
{
    return this->_target;
}

void        PresidentalPardonForm::setTarget( std::string target )
{
    this->_target = target;
}

void        PresidentalPardonForm::action ( void ) const
{
    std::cout << "**********************************************" << std::endl;
    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
    std::cout << "**********************************************" << std::endl;
}
