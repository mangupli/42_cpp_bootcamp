#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "Form.class.hpp"
#include <stdlib.h>      /* srand, rand */
#include <time.h> 

class RobotomyRequestForm : public Form {

private:

    std::string _target;
    RobotomyRequestForm( void );

public:

    RobotomyRequestForm( std::string target );
    RobotomyRequestForm( RobotomyRequestForm const & other );
    ~RobotomyRequestForm( void ){}

    RobotomyRequestForm & operator=( RobotomyRequestForm const & other );

    std::string getTarget( void ) const;
    void        setTarget( std::string target );
    void        action ( void ) const;
    Form        *makeCopy( void ) const;

};

#endif

// ShrubberyCreationForm (Required grades: sign 145, exec 137). Action: Create
// a file called <target>_shrubbery, and write ASCII trees inside it, in the current
// directory.
// • RobotomyRequestForm (Required grades: sign 72, exec 45). Action: Makes some
// drilling noises, and tell us that <target> has been robotomized successfully 50% of
// the time. Otherwise, tell us it’s a failure.
// • PresidentialPardonForm (Required grades: sign 25, exec 5). Action: Tells us
// <target> has been pardoned by Zafod Beeblebrox.
// All of these will have to take only one parameter in their constructor, which will
// represent the target of the form. For example, "home" if you want to plant shrubbery at
// home. Remember the form’s attributes need to remain private, and in the base class.