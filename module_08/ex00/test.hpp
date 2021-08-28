#ifndef TEST_H
# define TEST_H


template<typename T>
void print( T const & container)
{
    typename T::const_iterator it = container.begin();
    for( ; it != container.end(); ++it )
        std::cout << *it << " ";
    
    std::cout << std::endl;
}


template<typename T>
void testNumbers( T & container, int number)
{
    std::cout << "-->Looking for " << number << std::endl;

    int found = easyfind(container, number);

    if (found != -1)
        std::cout << "-->Found in place #"  << found << std::endl;
    else
        std::cout << "-->Not found"<< std::endl;
}


template<typename T>
void test( T & container)
{
    std::cout << " myContainer is: ";
    print(container);
    std::cout << std::endl;
    
    testNumbers(container, -42);

    std::cout << std::endl;

    testNumbers(container, 42);

    std::cout << std::endl;

}




#endif