#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

# include <string>
# include <iostream>
# include <exception>
# include "Form.class.hpp"

class Form;

class Bureaucrat {

private:

    std::string const   _name;
    int                 _grade;

    void setGrade( int const grade );
    
    Bureaucrat( void );

public:

    Bureaucrat( std::string const name, int grade );
    Bureaucrat( Bureaucrat const & other );
    ~Bureaucrat( void );

    Bureaucrat & operator=( Bureaucrat const & other );    
    
    std::string getName( void ) const;
    int         getGrade( void ) const ;

    void        plusGrade( void );
    void        minusGrade( void );
    void        signForm( Form & form );

    class GradeTooLowException: public std::exception {
    public:
        char const * what() const throw() { return "Grade too low"; } 
    }; 

    class GradeTooHighException: public std::exception {
    public:
        virtual char const * what() const throw() { return ("Grade too high"); }    
    };

};

std::ostream &	operator<<(std::ostream & out, Bureaucrat const & b);


#endif
