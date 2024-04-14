#ifndef ARRAY_HPP_INCLUDED
#define ARRAY_HPP_INCLUDED

#include <cstddef>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(Array other);
	~Array();

	void 					swap(Array& other);

	T& 						operator[](unsigned int i);
	const T& 			operator[](unsigned int i) const;

	unsigned int	size() const;

	void 					print(std::string arrayName) const;

private:
	T* 						_data;
	unsigned int	_size;

	void 					_copyData(T* dst, T* src, unsigned int size);
	void 					_checkBounds(unsigned int i) const;
};

template <typename T>
void swap(Array<T>& left, Array<T>& right);

#include "../src/Array.tpp"

#endif /* ARRAY_HPP_INCLUDED */
