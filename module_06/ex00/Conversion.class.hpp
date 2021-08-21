#ifndef CONVERSION_CLASS_H
# define CONVERSION_CLASS_H

#include <iostream>
#include <string> // stof, stod
#include <climits>
#include <iomanip>
#include <cfloat>

class Conversion {

private:

    std::string const   _string;
    bool                _valid;
    double              _doubleValue;
    bool                _doubleOverflow;

    char                stringToChar( void ) const;
    int                 stringToInt( void ) const;
    float               stringToFloat( void ) const;
    bool                stringIsNan( void ) const;
    bool                stringIsInf( void ) const;
    
    Conversion( void ){}

public:
    Conversion( std::string const string );
    Conversion( Conversion const & other );
    ~Conversion( void ) {}

    Conversion & operator=( Conversion const & ) = delete;

    std::string     getString( void ) const { return this->_string; }
    double          getDoubleValue( void ) const { return this->_doubleValue; }
    
 

    void            displayChar( void ) const;
    void            displayInt( void ) const;
    void            displayFloat( void ) const;
    void            displayDouble( void ) const;   

    class NonDisplayble: public std::exception {
    public:
        char const * what() const throw() { return "non displayble"; } 
    }; 

    class Impossible: public std::exception {
    public:
        char const * what() const throw() { return "impossible"; } 
    };         

};

#endif