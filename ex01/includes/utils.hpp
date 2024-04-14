#ifndef UTILS_HPP_INCLUDED
# define UTILS_HPP_INCLUDED

#include <iostream>

#include "colors.h"

template <typename T>
void printArray(T* array, size_t length)
{
    std::cout << RED "Array: " << GREEN;
    for (size_t i = 0; i < length; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << RESET << std::endl;
}

template <typename T>
void increment(T& value)
{
	value++;
}

template <typename T>
void print(T& value)
{
    std::cout << value << std::endl;
}

#endif /* UTILS_HPP_INCLUDED */
