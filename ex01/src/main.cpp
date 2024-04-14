#include <iostream>

#include "iter.hpp"
#include "utils.hpp"
#include "colors.h"


void decrement(int& value);

int main(void)
{
	std::cout << YELLOW << "------- Testing with arrayInt -------" << RESET << std::endl;
	int arrayInt[10] = {0,1,2,3,4,5,6,7,8,9};

	printArray(arrayInt, 10);
	std::cout << YELLOW << "Incrementing arrayInt: " 
						<< BLUE << "instantiating template increment<int>"
	<< RESET << std::endl;
	iter(arrayInt, 10, increment<int>);
	printArray(arrayInt, 10);

	std::cout << YELLOW << "Decrementing arrayInt: "
						<< BLUE << "normal function"
						<< RESET << std::endl;
	iter(arrayInt, 10, decrement);
	printArray(arrayInt, 10);
	std::cout << std::endl;


	std::cout << YELLOW << "------- Testing with arrayChar -------" << RESET << std::endl;
	char arrayChar[] = "abcdefghij";

	std::cout << YELLOW << "Printing arrayChar: " 
						<< BLUE << "instantiating template print"
						<< RESET << std::endl;
	iter(arrayChar, 10, print);

	std::cout << YELLOW << "Incrementing arrayChar: "
						<< BLUE << "instantiating template increment<char>"
						<< RESET << std::endl;
	iter(arrayChar, 10, increment<char>);

	std::cout << YELLOW << "Printing arrayChar: " 
						<< BLUE << "instantiating template print"
						<< RESET << std::endl;
	iter(arrayChar, 10, print);

	return 0;
}

void decrement(int& value)
{
  value--;
}