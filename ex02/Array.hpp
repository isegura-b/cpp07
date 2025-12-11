#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
private:
    T *_data;
    std::size_t _size;

public:
    Array();
    Array(unsigned int n);
    Array(Array const &other);
    Array &operator=(Array const &other);
    ~Array();

    T &operator[](std::size_t idx);
    T const &operator[](std::size_t idx) const;

    std::size_t size() const;

    // ecxeption index out of bounds
    class IndexOutOfBounds : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#include "Array.tpp"

#endif
