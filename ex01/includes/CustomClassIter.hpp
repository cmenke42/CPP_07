#ifndef CUSTOMCLASSITER_HPP
#define CUSTOMCLASSITER_HPP

#include <iosfwd>

class CustomClassIter
{
	public:
		CustomClassIter();
		CustomClassIter(const CustomClassIter& other);
		CustomClassIter& operator=(const CustomClassIter& other);
		~CustomClassIter();

		int getData() const;

	private:
		int data;
};

std::ostream& operator<<(std::ostream& o, const CustomClassIter& rhs);

#endif /* CUSTOMCLASSITER_HPP */
