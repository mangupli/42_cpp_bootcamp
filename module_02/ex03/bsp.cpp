/*
 * BSP stands for Binary space partitioning
 */

#include "Point.class.hpp"

float distance(Point const & a, Point const & b)
{
	return(std::sqrtf( std::powf((a.getX().toFloat() - b.getX().toFloat()), 2) +
					  std::powf((a.getY().toFloat() - b.getY().toFloat()), 2)));
}

float calculateTriangleArea(Point const & a, Point const & b, Point const & c)
{
	float firstSide = distance(a, b);
	float secondSide = distance(b, c);
	float thirdSide = distance(c, a);

	float p = (firstSide + secondSide + thirdSide) / 2.0; // is the semi-perimeter of a triangle

	return (std::sqrtf(p * (p - firstSide) * (p - secondSide) * (p - thirdSide)));
}

bool definePosition(float areaSrc, float area1, float area2, float area3)
{
	if (area1 != 0 && area2 != 0 && area3 != 0) // it means the point lies on the vertex/side
	{
		float res = areaSrc - (area1 + area2 + area3);

		if (res < 0)
			res *= -1;
		if (res == 0 || res < 0.001)
			return (true); // the point lies inside of a triangle
	}
	return (false); // the point lies on the vertex/side or outside the triangle
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float areaSrc = calculateTriangleArea(a, b, c);

	float area1 = calculateTriangleArea(a, b, point);
	float area2 = calculateTriangleArea(a, point, c);
	float area3 = calculateTriangleArea(point, b, c);

	return (definePosition(areaSrc, area1, area2, area3));
}
