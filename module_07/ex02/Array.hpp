#ifndef ARRAY_H
# define ARRAY_H

# include <exception>

template <typename T>
class Array
{

private:

    T *             _arrayPtr;
    unsigned int    _size;

public:

    Array( void ): _arrayPtr(0), _size(0) {}

    Array( int n ):_size(static_cast<unsigned int>(n))
    {
        if(n < 0)
            throw InvalidIndexException();
        else if (n == 0)
            _arrayPtr = 0;
        else
            _arrayPtr = new T[n];
        for(unsigned int i = 0; i < this->_size; ++i)
            this->_arrayPtr[i] = 0;

    }

    Array( Array const & other ): _arrayPtr(0),
                                _size(other._size)     
    {
        if(other._size)
        {
            this->_arrayPtr = new T[this->_size];
            for(unsigned int i = 0; i < this->_size; ++i)
                this->_arrayPtr[i] = other._arrayPtr[i];
        }
    }

    ~Array( void ) { delete[] _arrayPtr; }

    Array & operator=( Array const & other )
    {
        if (this != &other)
        {
            this->_size = other._size;
            
            delete[] this->_arrayPtr;
            this->_arrayPtr = 0;

            if (other._size)
            {
                this->_arrayPtr = new T[this->_size];
                for(unsigned int i = 0; i < this->_size; ++i)
                    this->_arrayPtr[i] = other._arrayPtr[i];
            }
        }
        return *this;
    }

    class InvalidIndexException: public std::exception
    {
        virtual char const * what() const throw() { return ("Invalid index"); }    
    };

    T & operator[]( int const index )
    {
        if(this->_size == 0 || index < 0 \
                    || static_cast<unsigned int>(index) >= this->_size)
            throw InvalidIndexException();

        return _arrayPtr[index];
    }

    T const & operator[]( int const index ) const
    {
         if(index < 0 || index >= this->_size)
            throw InvalidIndexException();
        
        return _arrayPtr[index];
    }

    unsigned int size( void ){ return this->_size; }

};

#endif



