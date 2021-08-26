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
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (tmp[i] != numbers[i])
        {
            std::cerr << "doesn't have the same value!!" << std::endl;
            return 1;
        }
    }
    }

    try
    {
        Array<char> charArray(-2); //invalid index
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        numbers[-2] = 0; // invalid index
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        numbers[MAX_VAL] = 0; // invalid index
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < 10; i++)
    {
        numbers[i] = i;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl; // ok
    }
    delete [] mirror;


    return 0;
}
