#include "iter.hpp"

template<typename T>
void print( T & elem )
{
	std::cout << elem << std::endl;
}

template<typename T>
void inc( T & elem )
{
	++elem;
}

//-----------------

int main()
{
	size_t arrayLength = 5;

	/*-------------------------------<int>------------------------------------*/

	std::cout << "---------------------<int>--------------------" << std::endl;
	int *intArray = new int[arrayLength];

	intArray[0] = 0;
	intArray[1] = 10;
	intArray[2] = 20;
	intArray[3] = 30;
	intArray[4] = 40;

	std::cout << "Print array elements:" << std::endl;
	iter<int>(intArray, arrayLength, print);

	std::cout << std::endl;

	std::cout << "Incrementing array elements...." << std::endl;
	iter<int>(intArray, arrayLength, inc);

	std::cout << std::endl;

	std::cout << "Print array elements:" << std::endl;
	iter<int>(intArray, arrayLength, print);

	delete[] intArray;

	/*---------------------------<ptr to NULL>--------------------------------*/

	std::cout << "----------------------<null>--------------------" << std::endl;

	int *nullArray = NULL;

	std::cout << "Print null array elements:" << std::endl;

	iter<int>(nullArray, arrayLength, print);

	/*-------------------------------<char>-----------------------------------*/

	std::cout << "---------------------<char>---------------------" << std::endl;

	char *charArray = new char[arrayLength];

	charArray[0] = 'a';
	charArray[1] = 'b';
	charArray[2] = 'c';
	charArray[3] = 'd';
	charArray[4] = 'e';

	std::cout << "Print array elements:" << std::endl;
	iter<char>(charArray, arrayLength, print);

	std::cout << std::endl;

	std::cout << "Incrementing array elements...." << std::endl;
	iter<char>(charArray, arrayLength, inc);

	std::cout << std::endl;

	std::cout << "Print array elements:" << std::endl;
	iter<char>(charArray, arrayLength, print);

	/*------------------------------<float>-----------------------------------*/

	std::cout << "------------------<float>------------------------" << std::endl;
	float *floatArray = new float[arrayLength];

	floatArray[0] = 0.1f;
	floatArray[1] = 10.1f;
	floatArray[2] = 20.1f;
	floatArray[3] = 30.1f;
	floatArray[4] = 40.1f;

	std::cout << "Print array elements:" << std::endl;
	iter<float>(floatArray, arrayLength, print);

	std::cout << std::endl;

	std::cout << "Incrementing array elements...." << std::endl;
	iter<float>(floatArray, arrayLength, inc);

	std::cout << std::endl;

	std::cout << "Print array elements:" << std::endl;
	iter<float>(floatArray, arrayLength, print);

	std::cout << "-----------------------------------------------" << std::endl;






}