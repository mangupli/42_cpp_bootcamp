#include "Span.class.hpp"

void    simpleTest( std::vector<int> & vector, unsigned int maxSize)
{
    std::vector<int>::iterator begin = vector.begin();
    std::vector<int>::iterator end = vector.end();

    Span span(maxSize);
    try
    {
        span.addRange(begin, end);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "container of ints: ";
    span.printNumbers();
    std::cout << "maxSize: " << span.getMaxSize() << std::endl;
    std::cout << "actualSize: " << span.getActualSize() << std::endl;
    if (begin != end)
    {
        std::cout << "maxElement: " << *std::max_element(begin, end) << std::endl;
        std::cout << "minElement: " << *std::min_element(begin, end) << std::endl;
    }
    
    try
    {
        std::cout << "longestSpan: " << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
         std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


int main()
{
    std::cout << "----------------------------------------" << std::endl;
    std::vector<int> emptyVector;
    std::cout << "testing empty vector" << std::endl << std::endl;
    simpleTest(emptyVector, 4);

    std::cout << "----------------------------------------" << std::endl;
    std::vector<int> vector1{42};
    std::cout << "testing vector with one element" << std::endl << std::endl;
    simpleTest(vector1, 1);

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "testing vector with one element, but size of span is 2" << std::endl << std::endl;
    simpleTest(vector1, 2);

    std::cout << "----------------------------------------" << std::endl;
    std::vector<int> maxMinVector{INT_MAX, INT_MIN};
    std::cout << "testing INT_MAX and INT_MIN" << std::endl << std::endl;
    simpleTest(maxMinVector, 2);

    std::cout << "----------------------------------------" << std::endl;
    std::vector<int> maxMaxVector{INT_MAX, INT_MAX};
    std::cout << "testing with two equals INT_MAX" << std::endl << std::endl;
    simpleTest(maxMaxVector, 2);

    std::cout << "----------------------------------------" << std::endl;
    std::vector<int> minMinVector{INT_MIN, INT_MIN};
    std::cout << "testing with two equals INT_MAX" << std::endl << std::endl;
    simpleTest(minMinVector, 4);
    
    std::cout << "----------------------------------------" << std::endl;
    std::vector<int> maxVector{INT_MAX, INT_MIN, -1, 1000};
    std::cout << "testing INT_MAX and INT_MIN with different elements" << std::endl << std::endl;
    simpleTest(maxVector, 4);
    std::cout << "----------------------------------------" << std::endl;

    std::vector<int> bigVector{42, 21, 0, 0,  -21, -42};
    std::cout << "testing adding range bigger than maxSize" << std::endl << std::endl;
    simpleTest(bigVector, 3);
    std::cout << "----------------------------------------" << std::endl;

    std::vector<int> veryBigVector;
    for(int i = -500; i < 500; ++i)
        veryBigVector.push_back(i * 3);
    std::cout << "testing vector with 1000 elements" << std::endl << std::endl;
    simpleTest(veryBigVector, 1000);
    std::cout << "----------------------------------------" << std::endl;


    
    

    return 0;
}
