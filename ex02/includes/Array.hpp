#ifndef ARRAY_HPP_INCLUDED
# define ARRAY_HPP_INCLUDED

#include <cstddef>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int size);
		Array(const Array& other);
		Array&			operator=(const Array& other);
		~Array();

        T&				operator[](unsigned int i);
    	const T&		operator[](unsigned int i) const;

		unsigned int 	size() const;
	
	private:
		T*				_data;
		unsigned int	_size;

		void			_copyData(T* dst, T* src, unsigned int size);
		void			_checkBounds(unsigned int i) const;
};

#include "Array.tpp"

#endif /* ARRAY_HPP_INCLUDED */
