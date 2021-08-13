#ifndef CAT_CLASS_H
# define CAT_CLASS_H

# include <string>
# include <iostream>

# include "Animal.class.hpp"

class Cat : public Animal {

public:
    Cat( void );
    Cat (Cat const & other);
    virtual ~Cat( void );

    Cat & operator=(Cat const & );

    virtual void    makeSound( void ) const;
    void            iAmCat ( void ) const;

};

#endif