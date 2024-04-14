#ifndef WHATEVER_HPP_INCLUDED
# define WHATEVER_HPP_INCLUDED

/**
 * @brief Swaps the values of two given arguments.
 *
 * @tparam T Type of the arguments.
 * @param[in,out] left First argument.
 * @param[in,out] right Second argument.
 */
template <typename T>
void swap(T& left, T& right)
{
	T temp(left)
	left = right;
	right = temp;
}

/**
 * @brief Compares two arguments. 
 *
 * @tparam T Type of the arguments.
 * @param[in] left First argument.
 * @param[in] right Second argument.
 * @return The smallest of the two arguments. Else the right one.
 * 
 * @note when a temporary object is bound to a const reference, its lifetime is extended to the lifetime of the reference
 */
template <typename T>
const T& min(const T& left, const T& right)
{
	if (left < right)
		return (left);
	return (right);
}

/**
 * @brief Compares two arguments. 
 *
 * @tparam T Type of the arguments.
 * @param[in] left First argument.
 * @param[in] right Second argument.
 * @return The greatest of the two arguments. Else the right one.
 * 
 * @note when a temporary object is bound to a const reference, its lifetime is extended to the lifetime of the reference
 */
template <typename T>
const T& max(const T& left, const T& right)
{
	if (left > right)
		return (left);
	return (right);
}

#endif /* WHATEVER_HPP_INCLUDED */
