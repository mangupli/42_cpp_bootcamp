#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed {

private:

	static int const	_fractionalBits = 8;
	int 				_value;

public:

	Fixed( void );
	Fixed(Fixed const &src);
	~Fixed( void );

	int			getRawBits( void ) const;
	void		setRawBits( int const rawBits );

	Fixed &		operator=( Fixed const & equalTo );

};

#endif