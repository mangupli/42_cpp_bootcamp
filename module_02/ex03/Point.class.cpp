#include "Point.class.hpp"

/*
 *  ---------------Constructors--------------------
 */

Point::Point( void ): _x(0), _y(0)
{
	return;
}

Point::Point(float const x, float const y): _x(Fixed(x)), _y(Fixed(y))
{
	return;
}

Point::Point(Point const &src): _x(src._x), _y(src._y)
{
	return;
}

Point::~Point( void )
{
	return;
}


Fixed const & Point::getX( void ) const
{
	return (this->_x);
}

Fixed const & Point::getY( void ) const
{
	return (this->_y);
}

/*
 *  --------------- Assignation operator --------------------
 */

Point &		Point::operator=( Point const & )
{
	return (*this);
}

/*
 *  --------------- Output operator --------------------
 */

std::ostream &	operator<<(std::ostream & out, Point const & point)
{
	out << "x = " << point.getX() << " y = " << point.getY();
	return out;
}




