#include <iostream>

#include "iter.hpp"
#include "utils.hpp"
#include "CustomClassIter.hpp"
#include "colors.h"


void decrement(int& value);

int main(void)
{
	std::cout << YELLOW << "------- Testing with arrayInt -------" << RESET << std::endl;
	int arrayInt[10] = {0,1,2,3,4,5,6,7,8,9};

	std::cout << YELLOW << "Printing arrayInt: " 
						<< BLUE << "instantiating template print<const int>"
						<< RESET << std::endl;
	iter(arrayInt, 10, print<const int>);

	std::cout << YELLOW << "Incrementing arrayInt: " 
						<< BLUE << "instantiating template increment<int>"
	<< RESET << std::endl;
	iter(arrayInt, 10, ::increment<int>);

	std::cout << YELLOW << "Printing arrayInt: " 
						<< BLUE << "instantiating template print<const int>"
						<< RESET << std::endl;
	iter(arrayInt, 10, print<const int>);

	std::cout << YELLOW << "Decrementing arrayInt: "
						<< BLUE << "normal function"
						<< RESET << std::endl;
	iter(arrayInt, 10, decrement);

	std::cout << YELLOW << "Printing arrayInt: " 
						<< BLUE << "instantiating template print<const int>"
						<< RESET << std::endl;
	iter(arrayInt, 10, print<const int>);
	std::cout << std::endl;


	std::cout << YELLOW << "------- Testing with arrayCustomClass -------" << RESET << std::endl;
	CustomClassIter arrayCustomClass[10];
	std::cout << YELLOW << "Printing arrayCustomClass: " 
						<< BLUE << "instantiating template print<CustomClassIter>"
						<< RESET << std::endl;
	iter(arrayCustomClass, 10, print<CustomClassIter>);
	return 0;
}

void decrement(int& value)
{
  value--;
}
