#include <iostream>

#include "Array.hpp"
#include "colors.h"
#include "CustomClass.hpp"

int main(void)
{
    std::cout << YELLOW << "------ Testing emptyArray ------" << RESET << std::endl;
    Array<int> emptyArray;
    std::cout << "emptyArray.size() = " << emptyArray.size() << std::endl;
    try
    {
        std::cout << "emptyArray[0] = " << emptyArray[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;


    std::cout << YELLOW << "------ Testing parmetric constructor ------" << RESET << std::endl;
    std::cout << BLUE << "Array<int> arrayInt(5)" << RESET << std::endl;
    Array<int> arrayInt(5);
    for (unsigned int i = 0; i < arrayInt.size(); i++)
    {
        std::cout << "arrayInt[" << i << "] = " << arrayInt[i] << std::endl;
    }
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
        std::cout << "arrayCustom[" << i << "] = " << arrayCustom[i].data << std::endl;
    }
    std::cout << std::endl;


    std::cout << YELLOW << "------ Testing copy constructor ------" << RESET << std::endl;
    std::cout << BLUE << "Array<int> arrayIntCopy(arrayInt)" << RESET << std::endl;
    Array<int> arrayIntCopy(arrayInt);
    for (unsigned int i = 0; i < arrayIntCopy.size(); i++)
    {
        std::cout << "arrayIntCopy[" << i << "] = " << arrayIntCopy[i] << std::endl;
    }
    std::cout << BLUE << "Incrementing arrayIntCopy values by 1" << RESET << std::endl;
    for (unsigned int i = 0; i < arrayIntCopy.size(); i++)
    {
        arrayIntCopy[i]++;
    }
    std::cout << BLUE << "arrayIntCopy values after incrementing by 1" << RESET << std::endl;
    for (unsigned int i = 0; i < arrayIntCopy.size(); i++)
    {
        std::cout << "arrayIntCopy[" << i << "] = " << arrayIntCopy[i] << std::endl;
    }
    std::cout << BLUE << "arrayInt values after incrementing arrayIntCopy" << RESET << std::endl;
    for (unsigned int i = 0; i < arrayInt.size(); i++)
    {
        std::cout << "arrayInt[" << i << "] = " << arrayInt[i] << std::endl;
    }
    std::cout << std::endl;


    std::cout << YELLOW << "------ Testing assignment operator ------" << RESET << std::endl;
    std::cout << BLUE << "Array<int> arrayIntAssign = arrayInt" << RESET << std::endl;
    Array<int> arrayIntAssign = arrayInt;
    for (unsigned int i = 0; i < arrayIntAssign.size(); i++)
    {
        std::cout << "arrayIntAssign[" << i << "] = " << arrayIntAssign[i] << std::endl;
    }
    std::cout << BLUE << "Decrementing arrayInt values by 1" << RESET << std::endl;
    for (unsigned int i = 0; i < arrayInt.size(); i++)
    {
        arrayInt[i]--;
    }
    std::cout << BLUE << "arrayInt values after decrementing by 1" << RESET << std::endl;
    for (unsigned int i = 0; i < arrayInt.size(); i++)
    {
        std::cout << "arrayInt[" << i << "] = " << arrayInt[i] << std::endl;
    }
    std::cout << BLUE << "arrayIntAssign values after decrementing arrayInt" << RESET << std::endl;
    for (unsigned int i = 0; i < arrayIntAssign.size(); i++)
    {
        std::cout << "arrayIntAssign[" << i << "] = " << arrayIntAssign[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "------ Testing out of bounds ------" << RESET << std::endl;
    std::cout << "Size of arrayInt: " << arrayInt.size() << std::endl;
    try
    {
        std::cout << "arrayInt[-1] = " << arrayInt[-1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    try
    {
        std::cout << "arrayInt[5] = " << arrayInt[5] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "------ Testing const for size() and operator[] ------" << RESET << std::endl;
    std::cout << BLUE << "Array<int> constArrayInt(5)" << RESET << std::endl;
    const Array<int> constArrayInt(5);
    std::cout << "constArrayInt.size() = " << constArrayInt.size() << "\n" << std::endl;
    for (unsigned int i = 0; i < constArrayInt.size(); i++)
    {
        std::cout << "constArrayInt[" << i << "] = " << constArrayInt[i] << std::endl;
    }
    std::cout << std::endl;


    return 0;
}