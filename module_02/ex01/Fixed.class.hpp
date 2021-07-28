#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <cmath>	// for roundf

class Fixed {

private:

	static int const	_fractionalBits = 8;
	int 				_value;

public:

	Fixed( void );
	Fixed ( int const value );
	Fixed ( float const value );
	Fixed( Fixed const &src );
	~Fixed( void );

	int			getRawBits( void ) const;
	void		setRawBits( int const rawBits );
	float 		toFloat ( void ) const;
	int 		toInt( void ) const;

	Fixed &			operator=( Fixed const & equalTo );

};

std::ostream &	operator<<(std::ostream & out, Fixed const & fixedValue);

#endif