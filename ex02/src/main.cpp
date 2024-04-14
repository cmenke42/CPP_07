#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

#include "Array.hpp"
#include "CustomClass.hpp"
#include "colors.h"

#define MAX_VAL 750

void testEmptyArray();
void testParametricConstructor();
void testDeepCopy();
void testAssignmentOperator();
void testOutOfBounds();
void testConstness();

int main(void)
{
    testEmptyArray();
    testParametricConstructor();
    testDeepCopy();
    testAssignmentOperator();
    testOutOfBounds();
    testConstness();
    return 0;
}


void testEmptyArray()
{
    std::cout << YELLOW << "------ Testing emptyArray ------" << RESET << std::endl;
    Array<int> emptyArray;
    std::cout << "emptyArray.size() = " << emptyArray.size() << std::endl;
    try
    {
        std::cout << "emptyArray[0] = " << emptyArray[0] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;
}

void testParametricConstructor()
{
    std::cout << YELLOW << "------ Testing parmetric constructor ------" << RESET << std::endl;
    std::cout << BLUE << "Array<int> arrayInt(5)" << RESET << std::endl;
    Array<int> arrayInt(5);
    arrayInt.print("arrayInt");
    std::cout << std::endl;

    std::cout << BLUE << "Comparison with: new int()" << RESET << std::endl;
    int *a = new int();
    std::cout << "*a = new int()" << std::endl;
    std::cout << "*a = " << *a << std::endl;
    delete a;
    std::cout << std::endl;

    std::cout << BLUE << "Array<CustomClass> arrayCustom(5)" << RESET << std::endl;
    Array<CustomClass> arrayCustom(5);
    for (unsigned int i = 0; i < arrayCustom.size(); ++i)
    {
        std::cout << "arrayCustom[" << i << "].data = " << arrayCustom[i].data << std::endl;
    }
    std::cout << std::endl;
}

void testDeepCopy()
{
    std::cout << YELLOW << "------ Starting deep copy test... ------" << RESET << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    std::cout << BLUE << "Filling array with random values..." << RESET << std::endl;
    std::srand(std::time(NULL));
    for (int i = 0; i < MAX_VAL; ++i)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    std::cout << BLUE << "Testing deep copy: " << RESET << std::endl;
    std::cout << "Array<int> tmp = numbers" << std::endl;
    std::cout << "Array<int> test(tmp)" << std::endl;
    //SCOPE -> testing proper deep copy and destructor
    try
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Exception caught during deep copy: " << e.what() << RESET << std::endl;
        delete [] mirror;
        throw;
    }

    std::cout << BLUE << "Verifying deep copy: mirror == numbers" << RESET << std::endl;
    for (int i = 0; i < MAX_VAL; ++i)
    {
        if (i < 10)
            std::cout << "numbers[" << i << "] = " << numbers[i] << "\t| mirror[" << i << "] = " << mirror[i] << std::endl;
        else if (i == 10)
            std::cout << "..." << std::endl;
        if (mirror[i] != numbers[i])
        {
            std::cout << RED << "Deep copy verification failed at index: " << i << RESET << std::endl;
            delete [] mirror;
            throw std::runtime_error("didn't save the same value!!");
        }
    }

    std::cout << GREEN <<  "Deep copy test passed!" << RESET << std::endl;
    delete [] mirror;
    std::cout << std::endl;
}

void testAssignmentOperator()
{
    std::cout << YELLOW << "------ Testing assignment operator ------" << RESET << std::endl;
    Array<int> arrayInt(5);
    std::cout << BLUE << "Setting arrayInt values to 9" << RESET << std::endl;
    for (unsigned int i = 0; i < arrayInt.size(); ++i)
    {
        arrayInt[i] = 9;
    }
    arrayInt.print("arrayInt");
    std::cout << BLUE << "Array<int> arrayIntAssign = arrayInt" << RESET << std::endl;
    Array<int> arrayIntAssign = arrayInt;
    arrayIntAssign.print("arrayIntAssign");
    std::cout << BLUE << "Decrementing arrayInt values by 1" << RESET << std::endl;
    for (unsigned int i = 0; i < arrayInt.size(); ++i)
    {
        arrayInt[i]--;
    }
    std::cout << BLUE << "arrayInt values after decrementing by 1" << RESET << std::endl;
    arrayInt.print("arrayInt");
    std::cout << BLUE << "arrayIntAssign values after decrementing arrayInt" << RESET << std::endl;
    arrayIntAssign.print("arrayIntAssign");
    std::cout << std::endl;
}

void testOutOfBounds()
{
    std::cout << YELLOW << "------ Testing out of bounds ------" << RESET << std::endl;
    Array<int> arrayInt(5);
    std::cout << "Size of arrayInt: " << arrayInt.size() << std::endl;
    try
    {
        std::cout << "arrayInt[-1] = " << arrayInt[-1] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    try
    {
        std::cout << "arrayInt[5] = " << arrayInt[5] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "Setting arrayInt[0] = 42" << RESET << std::endl;
    arrayInt[0] = 42;
    arrayInt.print("arrayInt");
    std::cout << std::endl;
}

void testConstness()
{
    std::cout << YELLOW << "------ Testing constness for size() and operator[] ------" << RESET << std::endl;
    std::cout << BLUE << "Array<int> constArrayInt(5)" << RESET << std::endl;
    const Array<int> constArrayInt(5);
    std::cout << "constArrayInt.size() = " << constArrayInt.size() << "\n" << std::endl;
    constArrayInt.print("constArrayInt");
    std::cout << std::endl;
}
