#ifndef SPAN_CLASS_H
# define SPAN_CLASS_H

# include <vector>
# include <iterator>
# include <algorithm>
# include <iostream>
# include <exception>
# include <climits>

class Span {

private:

    std::vector<int>    _vector;
    unsigned int        _maxSize;

    Span( void );

public:

    Span( unsigned int n );
    Span( Span const & other );
    virtual ~Span( void );

    Span & operator=(Span const & other);

    unsigned int        getMaxSize( void ) const;
    unsigned int        getActualSize( void ) const;
    void                printNumbers( void ) const;

    void                addNumber( int number );
    void                addRange(std::vector<int>::iterator start,
                                     std::vector<int>::iterator end);
    unsigned int        shortestSpan( void );
    unsigned int        longestSpan( void );

    class ExceedTheLimitException: public std::exception {
    public:
        char const * what() const throw();
    };

    class NoSpanException: public std::exception {
    public:
        char const * what() const throw();
    };

};

#endif