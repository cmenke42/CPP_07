#ifndef UTILS_HPP_INCLUDED
# define UTILS_HPP_INCLUDED

#include <iostream>

template <typename T>
void increment(T& value)
{
	value++;
}

template <typename T>
void print(const T& value)
{
    std::cout << value << std::endl;
}

#endif /* UTILS_HPP_INCLUDED */
