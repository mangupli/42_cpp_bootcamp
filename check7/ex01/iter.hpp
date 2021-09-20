#ifndef ITER_H
# define ITER_H

# include <string>
# include <iostream>

template<typename T>
void iter( T * array, size_t const arrayLength, void (*f)( T & elem ))
{
	if (array)
	{
		for( size_t i = 0; i < arrayLength; ++i) // check if array == null
			f(array[i]);
	}
	else
		std::cout << "pointer to array is NULL :(" << std::endl;
}

#endif