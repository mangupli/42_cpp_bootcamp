#include "Span.class.hpp"

int main()
{
    std::vector<int> myVector{INT_MAX, INT_MIN, -1, 1000};
    std::vector<int>::iterator begin = myVector.begin();
    std::vector<int>::iterator end = myVector.end();
    
    Span span(4);
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
    std::cout << "maxElement: " << *std::max_element(begin, end) << std::endl;
    std::cout << "minElement: " << *std::min_element(begin, end) << std::endl;

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
    
    
   


    
    return 0;
}
