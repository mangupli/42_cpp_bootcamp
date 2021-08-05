#include "Fixed.class.hpp"

/*
 *  ---------------Constructors--------------------
 */

Fixed::Fixed ( void ): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed ( int const value ): _value(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed ( float const value )
{
	std::cout << "Float constructor called" << std::endl;

	float rawBits = value * std::pow(2, _fractionalBits);
	_value = std::roundf(rawBits);

	return ;
}

Fixed::Fixed ( Fixed const &src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/*
 *  --------------- Assignation operator --------------------
 */

Fixed &		Fixed::operator=( Fixed const & equalTo )
{
	std::cout << "Assignment operator called" << std::endl;

	if (this != &equalTo)
		this->_value = equalTo.getRawBits();

	return *this;
}

/*
 *  --------------- Output operator --------------------
 */

std::ostream &	operator<<(std::ostream & out, Fixed const & fixedValue)
{
	out << fixedValue.toFloat();
	return out;
}

/*
 *  --------------- Comparison operators --------------------
 */

bool		Fixed::operator>(Fixed const & fixedCompared) const
{
	return (this->_value > fixedCompared.getRawBits());
}

bool		Fixed::operator>=(Fixed const & fixedCompared) const
{
	return (this->_value >= fixedCompared.getRawBits());
}

bool		Fixed::operator<(Fixed const & fixedCompared) const
{
	return (this->_value < fixedCompared.getRawBits());
}

bool		Fixed::operator<=(Fixed const & fixedCompared) const
{
	return (this->_value <= fixedCompared.getRawBits());
}

bool		Fixed::operator==(Fixed const & fixedCompared) const
{
	return (this->_value == fixedCompared.getRawBits());
}

bool		Fixed::operator!=(Fixed const & fixedCompared) const
{
	return (this->_value != fixedCompared.getRawBits());
}

/*
 *  --------------- Arithmetic operators --------------------
 */

Fixed 		Fixed::operator+(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed 		Fixed::operator-(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed 		Fixed::operator*(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed 		Fixed::operator/(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

/*
 *  --------------- Increment and decrement operators --------------------
 */

Fixed	&Fixed::operator++(void)
{
	++this->_value;

	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	--this->_value;

	return (*this);
}

Fixed 		Fixed::operator++( int )
{
	Fixed tmp(*this);

	++(*this);

	return (tmp);
}

Fixed 		Fixed::operator--( int )
{
	Fixed tmp(*this);

	--(*this);

	return (tmp);
}

/*
 * Different perspective on the increment and decrement operator
 *
 *	Fixed &		Fixed::operator++( void )
 *	{
 *		this->_value = (this->toFloat() + 1.0) * std::pow(2, this->_fractionalBits);
 *		return (*this);
 *	}
 *
 *	Fixed &		Fixed::operator--( void )
 *	{
 *		this->_value = (this->toFloat() - 1.0) * std::pow(2, this->_fractionalBits);
 *		return (*this);
 *	}
*/

/*
 *  ---------------Methods--------------------
 */

int Fixed::getRawBits( void ) const
{
	return this->_value;
}

void Fixed::setRawBits( int const rawBits )
{
	this->_value = rawBits;
	return ;
}

float Fixed::toFloat ( void ) const
{
	return ( 1.0 * this->_value) / std::pow(2, _fractionalBits);
}

int Fixed::toInt ( void ) const
{
	float rawBits = ( 1.0 * this->_value) / std::pow(2, _fractionalBits);
	return (roundf(rawBits));
}

Fixed & Fixed::min(Fixed & first, Fixed & second)
{
	return (first > second ? second : first);
}

Fixed const & Fixed::min(Fixed const & first, Fixed const & second)
{
	return (first > second ? second : first);
}

Fixed & Fixed::max(Fixed & first, Fixed & second)
{
	return (first > second ? first : second);
}

Fixed const & Fixed::max(Fixed const & first, Fixed const & second)
{
	return (first > second ? first : second);
}
