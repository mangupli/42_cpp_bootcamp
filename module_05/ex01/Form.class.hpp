#ifndef FORM_CLASS_H
# define FORM_CLASS_H

#include <string>
#include <exception>
#include <iostream>

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
    ~Form( void );

    Form & operator=( Form const & other );


    int         getGradeRequiredToSign( void ) const;
    int         getGradeRequiredToExecute( void ) const;
    std::string getIsSigned( void ) const;
    std::string getName( void ) const;

    class GradeTooLowException: public std::exception {
    public:
        char const * what() const throw() { return "Grade too low"; } 
    }; 

    class GradeTooHighException: public std::exception {
    public:
        virtual char const * what() const throw() { return ("Grade too high"); }    
    };

};

std::ostream &	operator<<(std::ostream & out, Form const & form);

#endif
