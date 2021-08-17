#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat {

private:

    std::string const   _name;
    int                 _grade;
    
    Bureaucrat( void ){}

public:

    Bureaucrat( std::string const name, int grade );
    Bureaucrat( Bureaucrat const & other );
    ~Bureaucrat( void ) {}

    Bureaucrat & operator=( Bureaucrat const & other );    
    
    std::string getName( void ) const;
    int         getGrade( void ) const ;
    void        setGrade( int const grade );

    class GradeTooLowException: public std::exception {
    public:
        char const * what() const { return "Grage too low"; } 
    }; 

    class GradeTooHighException: public std::exception {
    public:
        const char* what() const { return "Grade too high"; }    
    };

};


#endif
