#include <list>
#include <iostream>
#include <iterator>
#include <stack>

#include "Mutantstack.class.hpp"

template<typename T>
void printMutant( MutantStack<T> & mutant )
{   
    std::cout << "printing elements: ";
    typename MutantStack<T>::iterator it = mutant.begin();
    typename MutantStack<T>::iterator ite = mutant.end();
    if (it == ite)
        std::cout << "<empty stack>";

    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

template<typename T>
void simpleTest( MutantStack<T> & mutant )
{
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Testing MutantStack with size: " << mutant.size() << std::endl;
    printMutant( mutant );
    std::cout << "pushing one element(111)!" << std::endl;
    mutant.push(111);
    std::cout << "new size: " << mutant.size() << std::endl;
    std::cout << "what's on top? --> " << mutant.top() << std::endl;
    printMutant( mutant );

    std::cout << "++mutant.begin() points at: " << *(++mutant.begin()) << std::endl;
    std::cout << "--mutant.end() points at: " << *(--mutant.end()) << std::endl;

    std::cout << "poping one element!" << std::endl;
    mutant.pop();
    std::cout << "new size: " << mutant.size() << std::endl;
    printMutant( mutant );

    std::cout << "----------------------------------" << std::endl;
}

int main()
{
    MutantStack<int> mstack;


    simpleTest(mstack); // testing empty stack

    mstack.push(21);

    simpleTest(mstack); // testing stack with one int

    mstack.pop();
    for(int i = 0; i < 5; ++i)
        mstack.push(i + 42);

    simpleTest(mstack); // testing stack with few ints

    std::cout << "testing operator=" << std::endl << "copy of our mutantStack:" << std::endl;
    MutantStack<int> copyMutant;
    copyMutant = mstack;
    printMutant(copyMutant);

    MutantStack<char> charStack;
    for(int i = 0; i < 5; ++i)
        charStack.push(static_cast<char>(i + 100));

    simpleTest(charStack); // testing char stack

    MutantStack<double> doubleStack;
    for(int i = 0; i < 5; ++i)
        doubleStack.push(i + 42.001);

    simpleTest(doubleStack); // testing double stack



    return 0; 
}