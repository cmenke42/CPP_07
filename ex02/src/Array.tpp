#include <stdexcept>

#include "Array.hpp"

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
Array<T>::Array(const Array& other) : _data(NULL)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	T*	temp = NULL;

	if (this == &other)
		return (*this);
	if (other.size() > 0)
	{
		try
		{
			temp = new T[other._size];
			_copyData(temp, other._data, other._size);
		}
		catch (const std::bad_alloc& e)
		{
			delete[] temp;
			throw;
		}
	}

	delete[] this->_data;
	this->_data = temp;
	this->_size = other._size;

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
void Array<T>::_copyData(T* dst, T* src, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
		dst[i] = src[i];
}

template <typename T>
void Array<T>::_checkBounds(unsigned int i) const
{
	if (i >= this->_size)
		throw std::exception();
}
