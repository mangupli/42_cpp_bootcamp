#include "Array.hpp"
#include <iostream>

int main()
{
   Array<int> array;

    std::cout << &array << std::endl;
   
    int * ptr = new int[20];

    std::cout << ptr << std::endl;

    delete[] ptr;

    std::cout << ptr << std::endl;

    ptr = NULL;

    std::cout << ptr << std::endl;
    
    return 0;
}