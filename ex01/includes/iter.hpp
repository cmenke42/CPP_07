#ifndef ITER_HPP_INCLUDED
# define ITER_HPP_INCLUDED

#include <cstddef>

/**
 * @brief Applies a function to each element of an array.
 *
 * @tparam T Type of the array elements.
 * @param[in, out] array A pointer to the first element of the array.
 * @param[in] length Number of elements in the array.
 * @param[in] func Applied on each array element.
 *
 * @note Does nothing if array is NULL.
 */
template <typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
    if (!array)
        return ;
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif /* ITER_HPP_INCLUDED */
