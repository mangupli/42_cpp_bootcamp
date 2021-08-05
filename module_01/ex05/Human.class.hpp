#ifndef HUMAN_CLASS_H
# define HUMAN_CLASS_H

#include "Brain.class.hpp"

class Human
{

public:

    Human();
    ~Human();

    Brain & getBrain( void ) const;
    std::string identify( void ) const;

private:

    Brain _brain;
};

#endif