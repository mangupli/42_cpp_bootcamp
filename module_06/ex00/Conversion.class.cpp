#include "Conversion.class.hpp"

/*
*-----------------Constructors-----------------
*/

Conversion::Conversion( std::string const string ): _string(string)
{
    try
    {
        _doubleValue = std::stod(string);
        _valid = true;
        _doubleOverflow = false;

    }
    catch(const std::invalid_argument& e)
    {
        _doubleValue = 0;
        _valid = false;
        _doubleOverflow = false;
    }
    catch(const std::out_of_range& e)
    {
        _valid = true;
        _doubleOverflow = true;
        _doubleValue = 0;
    }
}

Conversion::Conversion( Conversion const & other ): Conversion(other._string){}


/*
*------------------Member functions-----------------
*/

bool    Conversion::stringIsInf( void ) const
{
    std::string tmpString(this->_string);

    for(unsigned long i = 1; i < tmpString.length(); ++i)
    {
        tmpString[i] = static_cast<char>(std::tolower(tmpString[i]));
    }
    if (tmpString == "+inf" || tmpString == "-inf" \
        || tmpString == "+inff" || tmpString == "-inff")
        return true;

    return false;
}

bool    Conversion::stringIsNan( void ) const
{
    std::string tmpString(this->_string);

    for(unsigned long i = 0; i < tmpString.length(); ++i)
    {
        tmpString[i] = static_cast<char>(std::tolower(tmpString[i]));
    }
    if (tmpString == "nan" || tmpString == "nanf")
        return true;

    return false;
}

/*
*--------------------Conversions---------------------
*/      

char   Conversion::stringToChar( void ) const
{
    if (this->_valid == false || this->_doubleOverflow == true)
        throw Conversion::Impossible();

    int intValue = static_cast<int>(this->_doubleValue);

    if ( intValue < SCHAR_MIN || intValue > SCHAR_MAX)
        throw Conversion::Impossible();
    else if (std::isprint(intValue) == false)
        throw Conversion::NonDisplayble();

    return static_cast<char>(intValue);
}

int   Conversion::stringToInt( void ) const
{
    if (this->_valid == false || this->_doubleOverflow == true)
        throw Conversion::Impossible();

    if (this->_doubleValue > static_cast<double>(INT_MAX) \
        || this->_doubleValue < static_cast<double>(INT_MIN) \
        || this->stringIsNan() == true)
        throw Conversion::Impossible();

    int intValue = static_cast<int>(this->_doubleValue);

    return intValue;
}

float   Conversion::stringToFloat( void ) const
{
    if (this->_valid == false || this->_doubleOverflow == true)
        throw Conversion::Impossible();

    if (this->stringIsInf() == false \
        && (this->_doubleValue > static_cast<double>(FLT_MAX) \
            || this->_doubleValue < static_cast<double>(-FLT_MAX)))
    {
       throw Conversion::Impossible();
    }
       
    float   floatValue = static_cast<float>(this->_doubleValue);

    return floatValue;
}

/*
*----------------------Display---------------------
*/ 

void    Conversion::displayChar( void ) const
{
    std::cout << "char: ";
    try
    {
        char value = this->stringToChar();
        std::cout << value << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    Conversion::displayInt( void ) const
{
    std::cout << "int: ";
    try
    {
        int value = this->stringToInt();
        std::cout << value << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    Conversion::displayFloat( void ) const
{
    std::cout << "float: ";
    try
    {
        float value = this->stringToFloat();
        std::cout << value << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    Conversion::displayDouble( void ) const
{
     std::cout << "double: ";
    try
    {
       if (this->_valid == false || this->_doubleOverflow == true)
       {
           throw Conversion::Impossible();
       }

    std::cout << this->_doubleValue << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
