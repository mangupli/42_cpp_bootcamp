#ifndef FORM_CLASS_H
# define FORM_CLASS_H

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.class.hpp"

class Bureaucrat;

class Form {

private:

    std::string const   _name;
    bool                _isSigned;
    int const           _gradeRequiredToSign;
    int const           _gradeRequiredToExecute;

    Form( void );

public:

    Form( std::string name, int gradeToSign, int gradeToExecute);
    Form( Form const & other );
    virtual ~Form( void );

    Form & operator=( Form const & other );


    int             getGradeRequiredToSign( void ) const;
    int             getGradeRequiredToExecute( void ) const;
    bool            getIsSigned( void ) const;
    std::string     getStatus( void ) const;
    std::string     getName( void ) const;

    void            setIsSigned( bool status );

    void            beSigned( Bureaucrat const & officer );
    void            execute(Bureaucrat const & executor) const;
    virtual void    action( void ) const = 0;

    class GradeTooLowException: public std::exception {
    public:
        char const * what() const throw() { return "Grade too low"; } 
    }; 

    class GradeTooHighException: public std::exception {
    public:
        virtual char const * what() const throw() { return ("Grade too high"); }    
    };

    class FormAlreadySignedException: public std::exception {
    public:
        virtual char const * what() const throw() { return ("Form already signed"); }    
    };

    class FormNotSignedException: public std::exception {
    public:
        virtual char const * what() const throw() { return ("Form not signed"); }    
    };

};

std::ostream &	operator<<(std::ostream & out, Form const & form);

#endif
