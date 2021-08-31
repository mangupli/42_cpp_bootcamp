#ifndef MUTANTSTACK_CLASS_H
# define MUTANTSTACK_CLASS_H

#include <stack>

/*
* It's a class that works exactly like std::stack but only
* with implemented iterators
* 
* In STL stack is based by default on std::deque container
* it looks something like this:
*
* template < class T, class Container = deque<T> >
* class stack {
*    protected:
*        Container C; ---> it's a base container for stack
*    public:
*        explicit    stack(const Container& = Container ());
*        bool        empty() const           { return c.empty(); }
*        size_type   size() const            { return c.size(); }
*        value_type& top()                   { return c.back(); }
*        const value_type& top() const       { return c.back(); }
*        void push(const valut_type & x)     { c.push_back(x); }
*        void pop()                          { c.pop_back(); }
*};
*
* So the same way std::stack derives all its methods from member type c,
* Mutantstack as a child of std::stack can reach protected member type c directly
* and get c's iterators implemented
*/

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

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin( void ) { return this->c.begin(); }
    iterator end( void ) { return this->c.end(); }

};

#endif //MUTANTSTACK_CLASS_H
