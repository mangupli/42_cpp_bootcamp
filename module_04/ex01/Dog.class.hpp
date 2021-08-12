#ifndef DOG_CLASS_H
# define DOG_CLASS_H

# include <string>
# include <iostream>

# include "Animal.class.hpp"
# include "Brain.class.hpp"

class Dog : public Animal {

private:

    Brain *_brain;

public:
    Dog( void );
    Dog (Dog const & other);
    virtual ~Dog( void );

    Dog & operator=(Dog const & Dog);

    virtual void    makeSound( void ) const;
    void            iAmDog( void ) const;

    Brain * getBrain( void ) const;

};

#endif