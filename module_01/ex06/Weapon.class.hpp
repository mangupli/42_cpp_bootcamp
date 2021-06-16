#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H

# include <iostream>
# include <string>

class Weapon
{

public:

    Weapon(std::string type);
    ~Weapon();

    const std::string &getType( void ) const;
    void setType (std::string type);

public:

    std::string _type;

};

#endif