#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL); //ok

    int* mirror = new int[MAX_VAL];

    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
			std::cout << "\033[0;31m[KO] didn't save the same value with int[]\033[0m\n" << std::endl;
            return 1;
        }
    }

	delete [] mirror;

	std::cout  << std::endl;
	std::cout << "\033[0;32m[OK] my array compared to int[] with many elements\033[0m\n" << std::endl;

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (tmp[i] != numbers[i])
        {
			std::cout << "\033[0;31m[KO] didn't save the same value copy constructor\033[0m\n" << std::endl;
            return 1;
        }
    }
		std::cout << "\033[0;32m[OK] copy constructor\033[0m\n" << std::endl;
    }

    try
    {
        Array<char> charArray(-2); //invalid index
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
		std::cout << "\033[0;32m[OK] invalid index\033[0m\n" << std::endl;
    }

    try
    {
        numbers[-2] = 0; // invalid index
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
		std::cout << "\033[0;32m[OK] invalid index\033[0m\n" << std::endl;
    }

    try
    {
        numbers[MAX_VAL] = 0; // invalid index
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
		std::cout << "\033[0;32m[OK] invalid index\033[0m\n" << std::endl;
    }

    for (int i = 0; i < 10; i++)
    {
        numbers[i] = i;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl; // ok
    }
	std::cout << "\033[0;32m[OK] overwritten and printed\033[0m\n" << std::endl;


    try{
		Array<char> emptyArray;
		std::cout << "\033[0;32m[OK] empty array\033[0m\n" << std::endl;
		std::cout << emptyArray[0] << std::endl;
    }
    catch (const std::exception& e)
    {
    	std::cerr << e.what() << '\n';
		std::cout << "\033[0;32m[OK] invalid index\033[0m\n" << std::endl;
    }


    Array<int> const constArray(numbers);
    for (int i = 0; i < 10; i++)
    {
    	std::cout << "constArray[" << i << "] = " << constArray[i] << std::endl; // ok
    }
	std::cout << "\033[0;32m[OK] const printed\033[0m\n" << std::endl;



    return 0;
}
