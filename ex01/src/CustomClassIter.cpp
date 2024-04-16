#include "CustomClassIter.hpp"

#include <ostream>

CustomClassIter::CustomClassIter() : data(42)
{
}

CustomClassIter::CustomClassIter(const CustomClassIter& other) : data(other.data)
{
}

CustomClassIter& CustomClassIter::operator=(const CustomClassIter& other)
{
	if (this != &other)
	{
		this->data = other.data;
	}
	return (*this);
}

CustomClassIter::~CustomClassIter() {}

int CustomClassIter::getData() const
{
	return (this->data);
}

std::ostream& operator<<(std::ostream& o, const CustomClassIter& rhs)
{
	o << rhs.getData();
	return (o);
}
