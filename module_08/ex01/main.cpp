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
    std::vector<int> vector1(1);
    vector1[0] = 42;
    std::cout << "testing vector with one element" << std::endl << std::endl;
    simpleTest(vector1, 1);

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "testing vector with one element, but size of span is 2" << std::endl << std::endl;
    simpleTest(vector1, 2);

    std::cout << "----------------------------------------" << std::endl;
    std::vector<int> maxMinVector(2);
    maxMinVector[0] = INT_MAX;
    maxMinVector[1] = INT_MIN;
    std::cout << "testing INT_MAX and INT_MIN" << std::endl << std::endl;
    simpleTest(maxMinVector, 2);

    std::cout << "----------------------------------------" << std::endl;
    std::vector<int> maxMaxVector(2);
    maxMinVector[0] = INT_MAX;
    maxMinVector[1] = INT_MAX;
    std::cout << "testing with two equals INT_MAX" << std::endl << std::endl;
    simpleTest(maxMaxVector, 2);

    std::cout << "----------------------------------------" << std::endl;
    std::vector<int> minMinVector(2);
    maxMinVector[0] = INT_MIN;
    maxMinVector[1] = INT_MIN;
    std::cout << "testing with two equals INT_MAX" << std::endl << std::endl;
    simpleTest(minMinVector, 4);
    
    std::cout << "----------------------------------------" << std::endl;
    std::vector<int> maxVector(4);
    maxVector[0] = INT_MAX;
    maxVector[1] = INT_MIN;
    maxVector[2] = -1;
    maxVector[3] = 1000;
    std::cout << "testing INT_MAX and INT_MIN with different elements" << std::endl << std::endl;
    simpleTest(maxVector, 4);
    std::cout << "----------------------------------------" << std::endl;

    std::vector<int> bigVector(6);
    bigVector[0] = 42;
    bigVector[11] = 21;
    bigVector[2] = 0;
    bigVector[3] = 0;
    bigVector[4] = -21;
    bigVector[5] = -42;

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
