#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array()
    : _data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
    : _data(NULL), _size(static_cast<std::size_t>(n))
{
    if (_size == 0)
    {
        _data = NULL;
        return;
    }
    _data = new T[_size];
}

template <typename T>
Array<T>::Array(Array const &other)
    : _data(NULL), _size(other._size)
{
    if (_size == 0)
    {
        _data = NULL;
        return;
    }
    _data = new T[_size];
    for (std::size_t i = 0; i < _size; ++i)
        _data[i] = other._data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    if (this == &other)
        return *this;

    T *newdata = NULL;
    std::size_t newsize = other._size;
    if (newsize > 0)
    {
        newdata = new T[newsize];
        for (std::size_t i = 0; i < newsize; ++i)
            newdata[i] = other._data[i];
    }

    if (_data)
        delete[] _data;

    _data = newdata;
    _size = newsize;
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    if (_data)
        delete[] _data;
}

template <typename T>
T &Array<T>::operator[](std::size_t idx)
{
    if (idx >= _size)
        throw IndexOutOfBounds();
    return _data[idx];
}

template <typename T>
T const &Array<T>::operator[](std::size_t idx) const
{
    if (idx >= _size)
        throw IndexOutOfBounds();
    return _data[idx];
}

template <typename T>
std::size_t Array<T>::size() const
{
    return _size;
}

template <typename T>
const char *Array<T>::IndexOutOfBounds::what() const throw()
{
    return "Array: index out of bounds";
}

#endif
