#ifndef CUSTOMCLASS_HPP
#define CUSTOMCLASS_HPP

class CustomClass
{
	public:
		CustomClass();
		CustomClass(const CustomClass& other);
		CustomClass& operator=(const CustomClass& other);
		~CustomClass();

		int data;
};

#endif /* CUSTOMCLASS_HPP */
