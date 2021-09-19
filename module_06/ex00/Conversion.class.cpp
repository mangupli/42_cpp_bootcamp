#include "Conversion.class.hpp"

/*
*-----------------Canonical form-----------------
*/

Conversion::Conversion( void ) {}

Conversion::Conversion( std::string const string ): _string(string)
{
	this->checkAndSetValue(string);
}

Conversion::Conversion( Conversion const & other ): _string(other._string)
{
	this->checkAndSetValue(other._string);
}

Conversion::~Conversion( void ) {}

Conversion &Conversion::operator=( Conversion const & ) { return *this; }

/*
*------------------Member functions-----------------
*/

bool    Conversion::stringIsInf( void ) const
{
    std::string tmpString(this->_string);

    for(unsigned long i = 0; i < tmpString.length(); ++i)
    {
        tmpString[i] = static_cast<char>(std::tolower(tmpString[i]));
    }
    if (tmpString == "+inf" || tmpString == "-inf" \
        || tmpString == "+inff" || tmpString == "-inff" \
        || tmpString == "inf" || tmpString == "inff")
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

void Conversion::checkAndSetValue( std::string const string )
{
	try
	{
		if (isNumber( string ) == false)
			throw std::invalid_argument("Invalid characters");
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
	_neededZero = checkIfNeededZero(_doubleValue);
}

bool Conversion::checkIfNeededZero(double const doubleValue) const
{
	int intValue = static_cast<int>(doubleValue);

	double diff = doubleValue - intValue;
	if (diff != 0 || lengthOfInt(intValue) > 6) // check if it is integer
		return false;
	return true;
}

bool Conversion::isDigit(int c) const
{
	if (c < 48 || c > 57)
		return false;
	return true;
}

bool Conversion::isNumber(std::string const & s ) const
{
	std::string::const_iterator	it		= s.begin();
	bool						decimal	= *it == '.'? true : false;

	if (this->stringIsInf() == true || this->stringIsNan() == true)
		return true;

	while (it != s.end())
	{
		if (it == s.begin() && (* it == '.' || *it == '-' || *it == '+'))
		{
			++it;
			continue;
		}
		if (*it == '.')
		{
			if (decimal == true) return false ;			// too many dots
			if (it + 1 == s.end()) return false;        //the dit in the end
			decimal = true;								// signal that one dot found
			++it;
			continue;
		}
		else if (isDigit(*it) == false)
		{
			if (!(it == s.end() - 1 && *it == 'f'))
				return false;
		}
		++it;
	}
	return true;
}

int Conversion::lengthOfInt( int const intValue ) const
{
	int numberOfDigits = 0;
	int copy = intValue;

	for(; copy; copy /= 10) numberOfDigits++;

	return (intValue == 0 ? 1 : numberOfDigits);
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
       
    float	floatValue = static_cast<float>(this->_doubleValue);

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
        std::cout << value;
        if (_neededZero == true)
        	std::cout << ".0";
        std::cout << "f" << std::endl;
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
    	std::cout << this->_doubleValue;
		if (_neededZero == true)
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

/*
*--------------------------Exceptions---------------------------
*/


const char *Conversion::NonDisplayble::what() const throw()
{
	return ("non displayble");
}

const char *Conversion::Impossible::what() const throw()
{
	return ("impossible");
}
