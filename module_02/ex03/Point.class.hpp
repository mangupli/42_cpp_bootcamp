#ifndef POINT_CLASS_H
# define POINT_CLASS_H

#include "Fixed.class.hpp"

class Point {

private:

	Fixed  const _x;
	Fixed  const _y;

public:

	Point( void );
	Point (float const x, float const y);
	Point( Point const &src );
	~Point( void );

	Point &		operator=( Point const & equalTo );

	Fixed const & getX( void ) const;
	Fixed const & getY( void ) const;

};

std::ostream &	operator<<( std::ostream & out, Point const & point );

#endif
