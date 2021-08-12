#ifndef DOG_CLASS_H
# define DOG_CLASS_H

# include <string>
# include <iostream>

# include "Animal.class.hpp"

class Dog : public Animal {

public:
    Dog( void );
    Dog (Dog const & other);
    virtual ~Dog( void );

    Dog & operator=(Dog const & );

    virtual void    makeSound( void ) const;
    void            iAmDog( void ) const;

};

#endif