#ifndef MUTANTSTACK_CLASS_H
# define MUTANTSTACK_CLASS_H

#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
    public:

    MutantStack( void ): std::stack<T>() {}
    MutantStack( std::stack<T> const & other ): std::stack<T>( other ) {}
    MutantStack( MutantStack const & other ): std::stack<T>( other ) {}
    virtual ~MutantStack( void ){}

    MutantStack & operator=( MutantStack const & other ) { 
        std::stack<T>::operator=(other);
        return *this;
    }

#   define container c

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin( void ) { return this->container.begin(); }
    iterator end( void ) { return this->container.end(); }

};

#endif //MUTANTSTACK_CLASS_H
