#ifndef AANIMAL_CLASS_H
# define AANIMAL_CLASS_H

# include <string>
# include <iostream>

class AAnimal {

protected:

    std::string _type;
    AAnimal( void );
    
public:
    
    AAnimal (AAnimal const & other);
    virtual ~AAnimal( void );
    AAnimal & operator=(AAnimal const & );

    std::string     getType( void ) const;
    virtual void    makeSound( void ) const = 0;

};

#endif