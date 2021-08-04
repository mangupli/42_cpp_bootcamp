#include <iostream>
#include "Fixed.class.hpp"

int main( void ) {

	Fixed a(7);
	Fixed b(9.3234f);


	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << ++b << std::endl;
	std::cout << b << std::endl;
	std::cout << ++b << std::endl;
	std::cout << b << std::endl;

	return 0;

}