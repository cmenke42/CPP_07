#include "CustomClass.hpp"

CustomClass::CustomClass() : data(42)
{
}

CustomClass::CustomClass(const CustomClass& other) : data(other.data)
{
}

CustomClass& CustomClass::operator=(const CustomClass& other)
{
	if (this != &other)
	{
		this->data = other.data;
	}
	return (*this);
}

CustomClass::~CustomClass() {}
