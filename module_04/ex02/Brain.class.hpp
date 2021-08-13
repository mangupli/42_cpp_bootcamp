#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

#include <string>
#include <iostream>

class Brain
{
public:

    Brain( void );
    Brain (Brain const & other);
    virtual ~Brain( void );

    Brain & operator=(Brain const & other);
    
    std::string *ideas;
};

#endif