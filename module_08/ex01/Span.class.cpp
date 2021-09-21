#include "Span.class.hpp"
/*
*------------------------------------Constructors-------------------------------
*/

Span::Span( void ) {}

Span::Span( unsigned int n ): _maxSize(n) {}

Span::Span( Span const & other ): _vector(other._vector),
                                _maxSize(other._maxSize) {}

/*
*------------------------------------Destructor---------------------------------
*/

Span::~Span( void ) {}

/*
*--------------------------------------Operators--------------------------------
*/

Span & Span::operator=(Span const & other)
{
    if (this != &other)
    {
        this->_maxSize = other._maxSize;
        this->_vector = other._vector;
    }
    return (*this);
}

/*
*----------------------------------------Getters--------------------------------
*/

unsigned int Span::getMaxSize( void ) const
{
    return this->_maxSize;
}

unsigned int Span::getActualSize( void ) const
{
    return static_cast<unsigned int>( this->_vector.size() );
}

/*
*----------------------------Member-functions-----------------------------------
*/

void Span::addNumber( int number )
{
    if (this->_maxSize <= this->getActualSize())
        throw ExceedTheLimitException();

    this->_vector.push_back( number );
}

void Span::addRange(std::vector<int>::iterator begin,
                                     std::vector<int>::iterator end)
{
    while (begin != end)
    {
        this->addNumber(*begin);
        ++begin;
    }
}

void Span::printNumbers( void ) const
{
    std::vector<int>::const_iterator it;

    it = this->_vector.begin();
    for ( ; it!= this->_vector.end(); ++it )
        std::cout << *it << " ";
    std::cout << std::endl;
}

unsigned int Span::shortestSpan( void )
{
    if(this->_vector.size() < 2)
        throw NoSpanException();

    std::sort(this->_vector.begin(), this->_vector.end());

    unsigned int shortestSpan = UINT_MAX;
    unsigned int diff;
    std::vector<int>::iterator it = this->_vector.begin();
    
    for( ; it != this->_vector.end() - 1; ++it)
    {
        diff = static_cast<unsigned int>(*(it + 1) - *it);
        if(diff < shortestSpan)
            shortestSpan = diff;
    }

    return shortestSpan;
}

unsigned int Span::longestSpan( void )
{
    if(this->_vector.size() < 2)
        throw NoSpanException();

    
    std::vector<int>::iterator begin = this->_vector.begin();
    std::vector<int>::iterator end = this->_vector.end();

    
    unsigned int longestSpan = \
            static_cast<unsigned int> \
            (*std::max_element(begin, end) \
                - *std::min_element(begin, end));

    return longestSpan;
}

/*
*--------------------------------Exceptions-------------------------------------
*/

char const * Span::ExceedTheLimitException::what() const throw()
{
	return "Can't store any more numbers";
}

char const * Span::NoSpanException::what() const throw()
{
	return "The span can't be found";
}
