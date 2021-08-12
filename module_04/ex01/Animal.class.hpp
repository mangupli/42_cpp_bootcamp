#ifndef ANIMAL_CLASS_H
# define ANIMAL_CLASS_H

# include <string>
# include <iostream>

class Animal {

protected:

    std::string _type;

public:
    Animal( void );
    Animal (Animal const & other);
    virtual ~Animal( void );

    Animal & operator=(Animal const & );

    std::string     getType( void ) const;
    virtual void    makeSound( void ) const;

};

#endif