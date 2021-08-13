#ifndef CAT_CLASS_H
# define CAT_CLASS_H

# include <string>
# include <iostream>

# include "Animal.class.hpp"
# include "Brain.class.hpp"

class Cat : public Animal {

private:

    Brain *_brain;

public:
    Cat( void );
    Cat (Cat const & other);
    virtual ~Cat( void );

    Cat & operator=(Cat const & );

    virtual void    makeSound( void ) const;
    void            iAmCat ( void ) const;

    std::string getIdea(int index) const;
    void        setIdea(int index, std::string idea);

};

#endif