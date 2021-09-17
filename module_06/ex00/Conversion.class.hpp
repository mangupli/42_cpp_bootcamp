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
    bool 				_neededZero;

    bool 				checkIfNeededZero(double const doubleValue ) const;
    int 				lengthOfInt( int const intValue ) const;
    char                stringToChar( void ) const;
    int                 stringToInt( void ) const;
    float               stringToFloat( void ) const;
    bool                stringIsNan( void ) const;
    bool                stringIsInf( void ) const;
    void 				checkAndSetValue( std::string const string );
    
    Conversion( void );

public:

    Conversion( std::string const string );
    Conversion( Conversion const & other );
    ~Conversion( void );

    Conversion & operator=( Conversion const & );

    std::string     getString( void ) const { return this->_string; }
    double          getDoubleValue( void ) const { return this->_doubleValue; }

    void            displayChar( void ) const;
    void            displayInt( void ) const;
    void            displayFloat( void ) const;
    void            displayDouble( void ) const;   

    class NonDisplayble: public std::exception {
    public:
        char const * what() const throw();
    }; 

    class Impossible: public std::exception {
    public:
        char const * what() const throw();
    };         

};

#endif