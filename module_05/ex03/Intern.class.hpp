#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H

#include "Form.class.hpp"
#define FORMSNUM 3

class Intern {

private:
    Form    *makeShrubCreatForm( std::string target );
    Form    *makePresPardForm( std::string target );
    Form    *makeRobReqForm( std::string target );

public:

    Intern( void ){}
    Intern( Intern const & other );
    ~Intern( void ){}

    Intern & operator=( Intern const & );

    Form    *makeForm(std::string nameOfForm, std::string target);

};

#endif
