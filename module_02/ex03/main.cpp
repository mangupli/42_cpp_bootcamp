#include <iostream>
#include "Point.class.hpp"

float distance(Point const & a, Point const & b);
float calculateArea(Point const & a, Point const & b, Point const & c);
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	Point a(1, 2);
	Point b(5, 2);
	Point c(3, 6);

	std::cout << "point a: " << a << std::endl;
	std::cout << "point b: " << b << std::endl;
	std::cout << "point c: " << c << std::endl;

	std::cout << "distance between a and b: " << distance(a, b) << std::endl;

	std::cout << "area of a triangle: " << calculateArea(a, b, c) << std::endl;


	return 0;
}

