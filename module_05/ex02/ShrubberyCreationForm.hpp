#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "Form.class.hpp"
# include <fstream>
# include <iostream>

class ShrubberyCreationForm : public Form {

private:

    std::string _target;
    ShrubberyCreationForm( void );

public:

    ShrubberyCreationForm( std::string target );
    ShrubberyCreationForm( ShrubberyCreationForm const & other );
    ~ShrubberyCreationForm( void ){}

    ShrubberyCreationForm & operator=( ShrubberyCreationForm const & other);

    std::string getTarget( void ) const;
    void        setTarget( std::string target );
    void        action ( void ) const;

};

#endif
