
#include <vector>
#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

#include "easyfind.hpp"
#include "test.hpp"



int main()
{
    int intArray[5] = {0, 42, -8, 108, 42};

    std::cout << "------------------<vector>------------------" << std::endl;

    std::vector<int> myVector(intArray, intArray + sizeof(intArray)/sizeof(int));

    test(myVector);

     std::cout << "------------------<list>------------------" << std::endl;

    std::vector<int> myList(intArray, intArray + sizeof(intArray)/sizeof(int));
    
    test(myList);


    return 0;
}