#ifndef ZOMBIE_CLASS_H
#define ZOMBIE_CLASS_H

#include <string>
#include <iostream>

class Zombie
{

public:

    Zombie(std::string name, std::string type);
    Zombie();
    ~Zombie();

    std::string getName( void ) const;
    std::string getType( void ) const;
    
    void setName( std::string name );
    void setType( std::string type );

    void announce( void ) const;

private:

    std::string _name;
    std::string _type;
};


#endif