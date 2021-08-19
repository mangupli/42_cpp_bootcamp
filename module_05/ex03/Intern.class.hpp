#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H

#include "Form.class.hpp"

class Intern {

public:

    Intern( void ){}
    Intern( Intern const & other );
    ~Intern( void ){}

    Intern & operator=( Intern const & );

    Form    *makeForm(std::string nameOfForm, std::string target);
};

#endif
