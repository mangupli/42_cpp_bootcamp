#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>

template< typename T >
int easyfind( T & container, int number )
{
    typename T::iterator it;

    it = std::find( container.begin(), container.end(), number );
    if( it != container.end() )
        return static_cast<int>(it - container.begin());
    else
        return -1;

}

#endif


