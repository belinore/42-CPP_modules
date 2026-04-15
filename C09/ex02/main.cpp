#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>

int run_tests()
{
    int ret = 0;
    try
    {
        PmergeMe pmergeMe(10000, NULL);
        pmergeMe.processInput();
        std::cout << "\n";
        PmergeMe pmergeMe2(10000, NULL);
        pmergeMe2.processInput();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        ret = 1;
    }
    return (ret);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        if (TEST_MODE)
            return (run_tests());
        std::cerr << "Error: expected usage ./PmergeMe <numbers...>\n";
        return (1);
    }
    try
    {
        PmergeMe pmergeMe(argc, argv);
        pmergeMe.processInput();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return (1);
    }
     return (0);
}