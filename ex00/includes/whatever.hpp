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
	T* pLeft = &left;
	T* pRight = &right;

	T temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

/**
 * @brief Compares two arguments. 
 *
 * @tparam T Type of the arguments.
 * @param[in] left First argument.
 * @param[in] right Second argument.
 * @return The smallest of the two arguments. Else the right one.
 */
template <typename T>
T& min(T& left, T& right)
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
 */
template <typename T>
T& max(T& left, T& right)
{
	if (left > right)
		return (left);
	return (right);
}

#endif /* WHATEVER_HPP_INCLUDED */
