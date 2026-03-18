#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i + 1;
    std::cout << "Integer Array: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << intArray[i] << " ";
    //std::cout << intArray << "\n";
    std::cout << "\n";
}