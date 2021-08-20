#include "Form.class.hpp"

/*
* --------Constructors---------
*/

Form::Form( void ):
                    _name("NoName"),
                    _isSigned( false ),
                    _gradeRequiredToSign(1),
                    _gradeRequiredToExecute(1)
                    
{
    /* std::cout << "Class Form default constructor called!" << std::endl; */
}


Form::Form( std::string name, int gradeToSign, int gradeToExecute):
                    _name(name),
                    _isSigned( false ),
                    _gradeRequiredToSign(gradeToSign),
                    _gradeRequiredToExecute(gradeToExecute)
                    
{
    /* std::cout << "Trying to create a form <" << name << ">..." << std::endl; */
    
    if ( gradeToExecute < 1 || gradeToSign < 1 )
        throw GradeTooHighException();
    if ( gradeToExecute > 150 || gradeToSign > 150 )
        throw GradeTooLowException();
    
    /* std::cout << "Done!" << std::endl; */
}

Form::Form( Form const & other ):
                    _name(other._name),
                    _isSigned( other._isSigned ),
                    _gradeRequiredToSign(other._gradeRequiredToSign),
                    _gradeRequiredToExecute(other._gradeRequiredToExecute)
                   
{
    /* std::cout << "Class Form copy constructor called!" << std::endl; */
}

Form::~Form ( void )
{
    /* std::cout << "Form destroyed!" << std::endl; */
}

/*
* ---------- Getters -------------
*/

std::string Form::getName( void ) const
{
    return this->_name;
}

int Form::getGradeRequiredToSign( void ) const
{
    return this->_gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute( void ) const
{
    return this->_gradeRequiredToExecute;
}

bool Form::getIsSigned( void ) const
{
    return this->_isSigned;
}

std::string Form::getStatus( void ) const
{
    if (this->_isSigned == true)
        return "is signed";
    else
        return "is not signed";
}

/*
* ----------- Operators -----------
*/

Form & Form::operator=( Form const & other )
{
   if (this != &other)
   {
    this->_isSigned = other._isSigned;
   }
    return *this;
}


std::ostream &	operator<<(std::ostream & out, Form const & form)
{
	out << "Form <" << form.getName() << ">: " << form.getStatus() << std::endl;
    out << "(Grade required to sign it: " << form.getGradeRequiredToSign()
    << "; Grade required to execute it: " << form.getGradeRequiredToExecute() << ")" << std::endl;
	return out;
}

/*
* --------- Member functioncs ----------
*/

void    Form::beSigned( Bureaucrat const & officer )
{
    if (this->_isSigned == true)
        throw FormAlreadySignedException();
    if ( officer.getGrade() <= this->_gradeRequiredToSign)
        this->_isSigned = true;
    else
        throw GradeTooLowException();
}

void        Form::setIsSigned( bool status )
{
    this->_isSigned = status;
}

void        Form::execute(Bureaucrat const & executor) const
{
    if (this->_isSigned == false)
        throw FormNotSignedException();
    if ( executor.getGrade() <= this->_gradeRequiredToExecute)
        this->action();
    else
        throw GradeTooLowException();
}