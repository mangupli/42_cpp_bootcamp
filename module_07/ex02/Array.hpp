#ifndef ARRAY_H
# define ARRAY_H

template <typename T>
class Array
{

private:

    T *             _arrayPtr;
    unsigned int    _size;

public:

    Array( void ): _arrayPtr(0), _size(0) {}

    Array( unsigned int n ):_size(n)
    {
        _arrayPtr = (n == 0) ? 0 : new T[n];
    }

    Array( Array const & other ): _arrayPtr(0),
                                _size(other._size)     
    {
        if(other._size)
        {
            this->_arrayPtr = new T[this->_size];
            for(int i = 0; i < this->_size; ++i)
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
                for(int i = 0; i < this->_size; ++i)
                    this->_arrayPtr[i] = other._arrayPtr[i];
            }
        }
        return *this;
    }
};


#endif



