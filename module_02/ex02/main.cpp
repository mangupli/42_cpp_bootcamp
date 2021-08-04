#include <iostream>
#include "Fixed.class.hpp"

int main( void ) {

	Fixed a(5.802f);
	Fixed b(5.802f);

	std::cout << (a != b) << std::endl;


	return 0;

}