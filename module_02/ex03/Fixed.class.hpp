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
	Fixed( int const value );
	Fixed( float const value );
	Fixed( Fixed const &src );
	~Fixed( void );

	int			getRawBits( void ) const;
	void		setRawBits( int const rawBits );
	float 		toFloat( void ) const;
	int 		toInt( void ) const;

	static		Fixed & min( Fixed & first, Fixed & second );
	static		Fixed const & min( Fixed const & first, Fixed const & second );
	static		Fixed & max( Fixed & first, Fixed & second );
	static		Fixed const & max( Fixed const & first, Fixed const & second );

	Fixed &		operator=( Fixed const & equalTo );

	bool		operator>( Fixed const & fixedCompared ) const;
	bool		operator>=( Fixed const & fixedCompared ) const;
	bool		operator<( Fixed const& fixedCompared ) const;
	bool		operator<=( Fixed const & fixedCompared ) const;
	bool		operator==( Fixed const & fixedCompared ) const;
	bool		operator!=( Fixed const & fixedCompared ) const;

	Fixed		operator+( Fixed const & fixedAdded ) const;
	Fixed		operator-( Fixed const & fixedAdded ) const;
	Fixed		operator*( Fixed const & fixedAdded ) const;
	Fixed		operator/( Fixed const & fixedAdded ) const;

	Fixed &		operator++( void ); // версия префикс
    Fixed &		operator--( void ); // версия префикс

    Fixed		operator++( int ); // версия постфикс
    Fixed		operator--( int ); // версия постфикс

};

std::ostream &	operator<<( std::ostream & out, Fixed const & fixedValue );

#endif