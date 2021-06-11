#ifndef PONY_CLASS_H
# define PONY_CLASS_H

#include <iostream>

enum Parents
{
    HEAP, //0
    STACK //1
};

class Pony
{
public:
    
    Pony( std::string name, int parent );
    ~Pony( void );

    void getName( void ) const;
    void getParent( void ) const;
    void getFavoriteMeal( void ) const;

    void setFavoriteMeal( std::string meal);

private:

    const std::string   _name;
    const int           _parent;
    std::string         _favoriteMeal;

};

#endif