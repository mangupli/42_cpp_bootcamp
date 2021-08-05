/*
 * BSP stands for Binary space partitioning :)
 */

#include "Point.class.hpp"

float distance(Point const & a, Point const & b)
{
	return(std::sqrtf( std::powf((a.getX().toFloat() - b.getX().toFloat()), 2) +
					  std::powf((a.getY().toFloat() - b.getY().toFloat()), 2)));
}

float calculateArea(Point const & a, Point const & b, Point const & c)
{
	float firstSide = distance(a, b);
	float secondSide = distance(b, c);
	float thirdSide = distance(c, a);

	float p = (firstSide + secondSide + thirdSide) / 2; // is the semi-perimeter of a triangle

	return (std::sqrtf(p * (p - firstSide) * (p - secondSide) * (p - thirdSide)));
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{

}