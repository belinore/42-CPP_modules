#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: expected usage ./btc <input_file>\n";
        return (1);
    }
    try
    {
        BitcoinExchange btc(argv[1]);
        btc.processInput();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return (1);
    }
     return (0);
}
