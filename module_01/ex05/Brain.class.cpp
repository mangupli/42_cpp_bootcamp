#include "Human.class.hpp"
#include "Brain.class.hpp"

Brain::Brain( void ): _searchForTheTruth(true), _creativity(true), _logic(true)
{
    std::cout << std::boolalpha << "God created this brain with following characteristics:" << std::endl <<\
    "searchForTheTruth = " << _searchForTheTruth << std::endl << \
    "creativity = " << _creativity << std::endl << \
    "logic = " << _logic << std::endl;
    
    std::stringstream string;
    string << this;
    this->_address = string.str();

    return ;
}

Brain::~Brain( void )
{
    return ;
}

std::string Brain::identify( void ) const
{
    return (this->_address);
}
