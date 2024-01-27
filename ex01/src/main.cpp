#include <iostream>

#include "iter.hpp"
#include "utils.hpp"



int main(void)
{
	// int array[2] = {1,2};

	char array[] = "123";

	printArray(array);

	::iter(array, 2, function);

	printArray(array);
	return 0;
}

