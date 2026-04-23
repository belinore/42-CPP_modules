/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:59:33 by belinore          #+#    #+#             */
/*   Updated: 2026/04/22 15:59:33 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

int run_tests()
{
    int ret = 0;
    try
    {
        srand(42);
        std::cout << CYAN << "Testing with 19 random numbers" << RESET << "\n";
        PmergeMe pmergeMe(19);
        pmergeMe.processInput();
        pmergeMe.printResults();
        std::cout << CYAN << "\nTesting with 500 random numbers" << RESET << "\n";
        PmergeMe pmergeMe1(500);
        pmergeMe1.processInput();
        pmergeMe1.printResults();
        std::cout << CYAN << "\nTesting with 10000 random numbers" << RESET << "\n";
        PmergeMe pmergeMe2(10000);
        pmergeMe2.processInput();
        pmergeMe2.printResults();
        std::cout << CYAN << "\nTesting with same 10000 numbers 10x" << RESET << "\n";
        for (size_t i = 0; i < 10; i++)
        {
            pmergeMe2.processInput();
            std::cout << pmergeMe2.getVectorTime() << " clock ticks for vector, " 
                      << pmergeMe2.getDequeTime() << " clock ticks for deque, "
                      << pmergeMe2.getListTime() << " clock ticks for list\n";
        }
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
        pmergeMe.printResults();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return (1);
    }
     return (0);
}