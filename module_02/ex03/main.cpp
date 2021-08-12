#include <iostream>
#include "Point.class.hpp"

float distance(Point const & a, Point const & b);
float calculateTriangleArea(Point const & a, Point const & b, Point const & c);
bool bsp( Point const a, Point const b, Point const c, Point const point);


void test (Point const a, Point const b, Point const c, Point const misteryPoint)
{
	std::cout << "Checking the following point: " << misteryPoint << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	if (bsp(a, b, c, misteryPoint) == true)
		std::cout << "This point lies INSIDE of a triangle" << std::endl;
	else
		std::cout << "This point lies OUTSIDE of a triangle" << std::endl;
}

int main( void ) {

	Point a(0.9, 2);
	Point b(5, 2);
	Point c(5, 6.7);

	std::cout << "point a: " << a << std::endl;
	std::cout << "point b: " << b << std::endl;
	std::cout << "point c: " << c << std::endl << std::endl;

//	std::cout << "distance between a and b: " << distance(a, b) << std::endl;

	std::cout << "area of a triangle: " << calculateTriangleArea(a, b, c)
	<< std::endl << std::endl;

	Point misteryPoint1(3, 2.1);
	Point misteryPoint2(5, 6.7);
	Point misteryPoint3(3, 1.9);

	std::cout << "=====================================" << std::endl;
	test(a, b, c, misteryPoint1);
	std::cout << "=====================================" << std::endl;
	test(a, b, c, misteryPoint2);
	std::cout << "=====================================" << std::endl;
	test(a, b, c, misteryPoint3);
	std::cout << "=====================================" << std::endl;

	return 0;
}

