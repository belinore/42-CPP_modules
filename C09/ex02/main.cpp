/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:59:33 by belinore          #+#    #+#             */
/*   Updated: 2026/05/12 17:12:18 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

void run_single_test(size_t n)
{
    std::cout << CYAN << "Testing with " << n << " random numbers" << RESET << "\n";
    PmergeMe pmergeMe(n);
    pmergeMe.processInput();
    pmergeMe.printResults();
}

void run_test_n_times(size_t n, size_t times)
{
    srand(42);
    std::cout << CYAN << "Testing with " << n << " random numbers " << times << "x" << RESET << "\n";
    PmergeMe pmergeMe(n);
    size_t totalVectorTime = 0;
    size_t totalDequeTime = 0;
    for (size_t i = 0; i < times; i++)
    {
        pmergeMe.processInput(true);
        pmergeMe.printResultsDetails();
        totalVectorTime += pmergeMe.getVectorTime();
        totalDequeTime += pmergeMe.getDequeTime();
    }
    size_t averageVectorTime = totalVectorTime / times;
    size_t averageDequeTime = totalDequeTime / times;
    std::cout << "Average time to sort " << n << " numbers: Vector -> " << averageVectorTime
              << " clock ticks, Deque -> " << averageDequeTime << " clock ticks\n\n";
}

int run_tests()
{
    int ret = 0;
    try
    {
        srand(42);
        run_single_test(1);
        run_single_test(5);
        run_single_test(19);
        run_single_test(500);
        run_single_test(10000);
        run_test_n_times(12, 5);
        run_test_n_times(10000, 5);
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
