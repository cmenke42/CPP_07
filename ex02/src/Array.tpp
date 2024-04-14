#include <stdexcept>
#include <iostream>

#include "Array.hpp"

/* -------------------------- class Array -------------------------- */

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
	this->_data = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; ++i)
	{
		this->_data[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array& other)
				: _data(NULL),
					_size(other._size)
{
	if (other.size() == 0)
		return ;
	this->_data = new T[other._size];
	try
	{
		_copyData(this->_data, other._data, other._size);
	}
	catch (const std::exception& e)
	{
		delete[] this->_data;
		this->_data = NULL;
		throw;
	}
}

template <typename T>
Array<T>& Array<T>::operator=(Array other)
{
	this->swap(other);
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (this->_data)
		delete[] this->_data;
	this->_data = NULL;
}

template <typename T>
void Array<T>::swap(Array& other)
{
	T* tempData = this->_data;
	this->_data = other._data;
	other._data = tempData;

	unsigned int tempSize = this->_size;
	this->_size = other._size;
	other._size = tempSize;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	_checkBounds(i);
	return (this->_data[i]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	_checkBounds(i);
	return (this->_data[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
void Array<T>::print(std::string arrayName) const
{
	for (unsigned int i = 0; i < this->_size; ++i)
	{
		std::cout << arrayName << "[" << i << "] = " << this->_data[i] << std::endl;
	}
}

template <typename T>
void Array<T>::_copyData(T* dst, T* src, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
		dst[i] = src[i];
}

/**
 * @brief This function checks if an index is within the bounds of the array.
 *
 * @tparam T The type of the elements in the array.
 * @param i The index to check.
 *
 * @throws std::exception -> If the index is not within the bounds of the array.
 */
template <typename T>
void Array<T>::_checkBounds(unsigned int i) const
{
	if (i >= this->_size)
		throw std::exception();
}


/* -------------------------- non-member functions -------------------------- */

template <typename T>
void swap(Array<T>& left, Array<T>& right)
{
	left.swap(right);
}
