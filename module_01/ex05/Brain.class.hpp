#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

#include <iostream>
#include <string>
#include <sstream>

class Brain 
{

public:

    Brain();
    ~Brain();

    std::string identify( void ) const;

private:

    bool        _searchForTheTruth;
    bool        _creativity;
    bool        _logic;
    std::string _address;

};
#endif