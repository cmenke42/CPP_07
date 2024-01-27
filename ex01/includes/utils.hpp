#ifndef UTILS_HPP_INCLUDED
# define UTILS_HPP_INCLUDED

#include <iostream>

template <typename T, size_t length>
void printArray(T (&array)[length]) {
    for (size_t i = 0; i < length; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void function(T& value)
{
	value++;
}

#endif /* UTILS_HPP_INCLUDED */
