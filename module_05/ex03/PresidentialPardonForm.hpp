#ifndef PRESIDENTALPARDONFORM_H
# define PRESIDENTALPARDONFORM_H

# include "Form.class.hpp"

class PresidentalPardonForm : public Form {

private:

    std::string _target;
    PresidentalPardonForm( void );

public:

    PresidentalPardonForm( std::string target );
    PresidentalPardonForm( PresidentalPardonForm const & other );
    ~PresidentalPardonForm( void ){}

    PresidentalPardonForm & operator=( PresidentalPardonForm const & other);

    std::string getTarget( void ) const;
    void        setTarget( std::string target );
    void        action( void ) const;
    Form        *makeCopy( void ) const;

};

#endif
