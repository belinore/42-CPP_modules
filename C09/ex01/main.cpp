#include "RPN.hpp"

#include <iostream>
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: expected usage ./rpn <expression>\n";
        return (1);
    }
    try
    {
        RPN reverse_polish_notation(argv[1]);
        reverse_polish_notation.processExpression();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return (0);
}
