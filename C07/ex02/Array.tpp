#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    _array = new T[n];
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _size(other.size())
{
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        delete[] _array;
        _array = new T[other.size()];
        _size = other.size();
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw IndexOutOfBoundsException();
    return (_array[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw IndexOutOfBoundsException();
    return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
    return ("Index out of bounds");
}

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> &array)
{
    for (unsigned int i = 0; i < array.size(); i++)
        os << array[i] << " ";
    return (os);
}
