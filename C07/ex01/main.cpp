#include "iter.hpp"
#include <iostream>

void printInt(const int &n)
{
    std::cout << "[" << n << "]";
}

void printChar(char &c)
{
    std::cout << c;
}

void encodeLowerChar(char &c)
{
    if (c == 'z')
        c = 'a';
    else
        c += 1;
}

void printTotalLetters(std::string &s)
{
    std::cout << s.length() << " ";
}

int main()
{
    const int array[] = {1, 2, 3, 4, 5};
    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    size_t len = 5;
    iter(array, len, printInt);
    std::cout << "\n";
    iter(charArray, len, printChar);
    std::cout << "\n";
    iter(charArray, len, encodeLowerChar);
    iter(charArray, len, printChar);
    std::cout << "\n";
    std::string str[] = {"Hello", "World", "!"};
    iter(str, 3, printTotalLetters);
    std::cout << "\n";
    return (0);
}
