#include <list>
#include <iostream>
#include <iterator>
#include <stack>

#include "Mutantstack.class.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    //[...]

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;

    MutantStack<int> copy;
    copy = mstack;
    MutantStack<int>::iterator itCopy = copy.begin();
    MutantStack<int>::iterator iteCopy = copy.end();
    while (itCopy != iteCopy)
    {
        std::cout << *itCopy << std::endl;
        ++itCopy;
    }

    return 0; 
}