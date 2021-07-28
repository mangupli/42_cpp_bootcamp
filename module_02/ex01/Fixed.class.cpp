#include "Fixed.class.hpp"

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

Fixed &		Fixed::operator=( Fixed const & equalTo )
{
	std::cout << "Assignment operator called" << std::endl;

	if (this != &equalTo)
		this->_value = equalTo.getRawBits();

	return *this;
}

int			Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void		Fixed::setRawBits( int const rawBits )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = rawBits;
	return ;
}






