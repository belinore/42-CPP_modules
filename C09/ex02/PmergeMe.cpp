/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:59:27 by belinore          #+#    #+#             */
/*   Updated: 2026/05/04 10:04:42 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>


static void validateArg(const std::string &arg)
{
    if (arg.empty())
        throw std::invalid_argument("Empty arguments are not allowed");
    
    for (size_t i = 0; i < arg.size(); i++)
    {
        if (!std::isdigit(arg[i]))
            throw std::invalid_argument("Only positive integers accepted (1 per arg)");
    }
}

PmergeMe::PmergeMe(int argc, char **argv) : _processed(false)
{
    if (!argv || argc < 1)
        throw std::invalid_argument(
            "Invalid parameters passed to PmergeMe constructor");
    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]);
        validateArg(arg);
        int num = std::atoi(argv[i]);
        if (num < 0)
            throw std::invalid_argument("Negative numbers are not allowed: "
                + std::string(argv[i]));
        _vector.push_back(num);
        _list.push_back(num);
        _deque.push_back(num);
    }
    _size = _vector.size();

}

PmergeMe::PmergeMe(size_t size) : _processed(false)
{
    if (size == 0)
        throw std::invalid_argument("Size must be greater than 0");
    for (size_t i = 0; i < size; i++)
    {
        int num = rand() % RANDOM_MAX;
        _vector.push_back(num);
        _list.push_back(num);
        _deque.push_back(num);
    }
    _size = size;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
: _vector(other._vector), _deque(other._deque), _list(other._list), _jacobsthal(other._jacobsthal)
, _jacobsthalDeque(other._jacobsthalDeque), _size(other._size), _processed (other._processed)
{
    if (other._processed)
    {
        _sortedVector = other._sortedVector;
        _sortedList = other._sortedList;
        _sortedDeque = other._sortedDeque;
        _vectorTime = other._vectorTime;
        _listTime = other._listTime;
        _dequeTime = other._dequeTime;
    }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
        _list = other._list;
        _jacobsthal = other._jacobsthal;
        _jacobsthalDeque = other._jacobsthalDeque;
        _size = other._size;
         _processed = other._processed;
        if (other._processed)
        {
            _sortedVector = other._sortedVector;
            _sortedList = other._sortedList;
            _sortedDeque = other._sortedDeque;
            _vectorTime = other._vectorTime;
            _listTime = other._listTime;
            _dequeTime = other._dequeTime;
        }
    }
    return (*this);
}

clock_t PmergeMe::getVectorTime() const { return (_vectorTime); }

clock_t PmergeMe::getListTime() const { return (_listTime); }

clock_t PmergeMe::getDequeTime() const { return (_dequeTime); }

/* The Merge-Insertion sort algorithm:
1) Divide the input into pairs of elements. 
   For each pair put largest in mainChain and smaller in pendants.
2) Recursively sort the main chain.
3) Insert the pendants back into the sorted main chain in the order
   defined by the Jacobsthal sequence, which minimises the number of comparisons 
   needed to find their correct position in the sorted main chain. */
// void PmergeMe::sortRecursiveVector(std::vector<int> &vector)
// {
//     if (vector.size() <= 1)
//         return;
//     std::vector<int> mainChain;
//     std::vector<int> pendants;
//     if (vector.size() % 2 != 0)
//         pendants.push_back(vector.back());
//     for (size_t i = 0; i < vector.size() - 1; i += 2)
//     {
//         if (vector[i] > vector[i + 1])
//         {   mainChain.push_back(vector[i]);
//             pendants.push_back(vector[i + 1]);
//         }
//         else
//         {
//             mainChain.push_back(vector[i + 1]);
//             pendants.push_back(vector[i]);
//         }
//     }
//     if (mainChain.size() > 1)
//         sortRecursiveVector(mainChain);
//     std::vector<size_t> order;
//     insertPendants(mainChain, pendants, order, _jacobsthal);
//     vector = mainChain;
// }

void PmergeMe::sortVectorRecursive(std::vector<std::pair<int,int>> &vector)
{
    if (vector.size() <= 1)
        return;
    bool hasStraggler = false;
    std::pair<int,int> straggler;
    if (vector.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = vector.back();
    }
    std::vector<std::pair<int,int>> mainChain;
    std::vector<std::pair<int,int>> pendants;
    for (size_t i = 0; i + 1 < vector.size(); i += 2)
    {
        if (vector[i].first > vector[i + 1].first)
        {   mainChain.push_back(vector[i]);
            pendants.push_back(vector[i + 1]);
        }
        else
        {
            mainChain.push_back(vector[i + 1]);
            pendants.push_back(vector[i]);
        }
    }
    sortVectorRecursive(mainChain);
    if (hasStraggler)
        pendants.push_back(straggler);
    vector = mainChain;
    insertPendants(mainChain, pendants, _jacobsthal);
    vector = mainChain;
}

void insert(std::vector<std::pair<int,int>> &mainChain, std::vector<std::pair<int,int>> &pendants, std::vector<size_t> &order)
{
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t idx = order[i];
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), pendants[idx]);
        mainChain.insert(it, pendants[idx]);
    }
}

void PmergeMe::sortVector(std::vector<int> &vector)
{
    if (vector.size() <= 1)
        return;
    bool hasStraggler = false;
    std::pair<int,int> straggler;
    if (vector.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = std::make_pair(vector.back(), vector.back());
    }
    std::vector<std::pair<int,int>> pairs;
    for (size_t i = 0; i + 1 < vector.size(); i += 2)
    {
        if (vector[i] > vector[i + 1])
            pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
        else
            pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
    }
    if (pairs.size() > 1)
        sortVectorRecursive(pairs);
    std::vector<size_t> order;
    jacobsthalInsertionOrder(pendants.size(), order, _jacobsthal);
    insert(pairs, order, _jacobsthal);
    vector = vectorFromPairs(pairs);
}

void PmergeMe::sortRecursiveDeque(std::deque<int> &deque)
{
    if (deque.size() <= 1)
        return;
    std::deque<int> mainChain;
    std::deque<int> pendants;
    if (deque.size() % 2 != 0)
        pendants.push_back(deque.back());
    for (size_t i = 0; i < deque.size() - 1; i += 2)
    {
        if (deque[i] > deque[i + 1])
        {   mainChain.push_back(deque[i]);
            pendants.push_back(deque[i + 1]);
        }
        else
        {
            mainChain.push_back(deque[i + 1]);
            pendants.push_back(deque[i]);
        }
    }
    if (mainChain.size() > 1)
        sortRecursiveDeque(mainChain);
    std::deque<size_t> order;
    insertPendants(mainChain, pendants, order, _jacobsthalDeque);
    deque = mainChain;
}

//linear search for the correct position to insert the pendant in the sorted main chain,
//since std::list does not support random access iterators required for std::lower_bound
static std::list<int>::iterator lower_bound_list(std::list<int>::iterator first, 
                                                 std::list<int>::iterator last, int value)
{
    while (first != last)
    {
        if (*first >= value)
            return first;
        ++first;
    }
    return (last);
}

//Simplified version of the merge-insertion sort for std::list, without using the Jacobsthal sequence for insertion order
void PmergeMe::sortRecursiveList(std::list<int> &list)
{
    std::list<int> mainChain;
    std::list<int> pendants;
    std::list<int>::iterator it = list.begin();
    while (it != list.end())
    {
        std::list<int>::iterator next = it;
        next++;
        if (next == list.end())
        {
            pendants.push_back(*it);
            break;
        }
        if (*it > *next)
        {   
            mainChain.push_back(*it);
            pendants.push_back(*next);
        }
        else
        {
            mainChain.push_back(*next);
            pendants.push_back(*it);
        }
        it = next;
        it++;
    }
    if (mainChain.size() > 1)
        sortRecursiveList(mainChain);
    for (std::list<int>::iterator it = pendants.begin(); it != pendants.end(); it++)
    {
        std::list<int>::iterator insertIt = lower_bound_list(mainChain.begin(), mainChain.end(), *it);
        mainChain.insert(insertIt, *it);
    }
    list = mainChain;
}

void PmergeMe::printResults()
{
    if (!_processed)
    {
        print_container(_vector, "Unsorted numbers: ");
        std::cout << "Call processInput() to sort\n";
        return ;
    }
    if (TEST_MODE)
        printResultsDetailed();
    else
        printResultsSimple();
}

void PmergeMe::printResultsDetailed()
{
    if (_vector.size() <= MAX_PRINT_SIZE)
    {
        print_container(_vector, "Original vector: ");
        print_container(_sortedVector, "Sorted vector: ");
        print_container(_deque, "Original deque: ");
        print_container(_sortedDeque, "Sorted deque: ");
        print_container(_list, "Original list: ");
        print_container(_sortedList, "Sorted list: ");
        std::cout << "\n";
    }
    std::cout << "Vector (size=" << _vector.size() << ")\n";
    std::cout << "Is sorted? " << (isSorted(_sortedVector) ? "YES" : "NO") << "\n";
    std::cout << "Time taken to sort vector: " << _vectorTime << " clock ticks\n\n";
    std::cout << "Deque of (size=" << _deque.size() << ")\n";
    std::cout << "Is sorted? " << (isSorted(_sortedDeque) ? "YES" : "NO") << "\n";
    std::cout << "Time taken to sort deque: " << _dequeTime << " clock ticks\n\n";
    std::cout << "List (size=" << _list.size() << ")\n";
    std::cout << "Is sorted? " << (isSorted(_sortedList) ? "YES" : "NO") << "\n";
    std::cout << "Time taken to sort list: " << _listTime << " clock ticks\n";
}

void PmergeMe::printResultsSimple()
{
    print_container(_vector, "Before: ");
    print_container(_sortedVector, "After: ");
    double vectorTimeMicro = static_cast<double>(_vectorTime) / CLOCKS_PER_SEC * 100000;
    double dequeTimeMicro = static_cast<double>(_dequeTime) / CLOCKS_PER_SEC * 100000;
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector : " << _vectorTime << " clock ticks "
              << "(" << std::fixed << std::setprecision(5) << vectorTimeMicro << " us)\n";
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << _dequeTime << " clock ticks "
              << "(" << std::fixed << std::setprecision(5) << dequeTimeMicro << " us)\n";}

// Process the input data, sort it using the merge-insertion sort algorithm, and measure the time taken for each container type. 
// The sorted results are stored in separate member variables to allow for comparison and verification of correctness.
// Can be sorted with template version or with specific implementations for each container type, depending on the value of USE_GENERIC macro.
void PmergeMe::processInput()
{
    _sortedDeque = _deque;
    _sortedList = _list;
    if (USE_GENERIC)
    {
        processInput_alt(_vector, _sortedVector, _vectorTime);
        processInput_alt(_deque, _sortedDeque, _dequeTime);
    }  
    else
    {
        clock_t start = clock();
        _sortedVector = _vector;
        buildJacobsthal(_size, _jacobsthal);
        sortRecursiveVector(_sortedVector);
        clock_t end = clock();
        _vectorTime = end - start;
        start = clock();
        _sortedDeque = _deque;
        buildJacobsthal(_size, _jacobsthalDeque);
        sortRecursiveDeque(_sortedDeque);
        end = clock();
        _dequeTime = end - start;
    }
    clock_t start = clock();
    _sortedList = _list;
    sortRecursiveList(_sortedList);
    clock_t end = clock();
    _listTime = end - start;
    _processed = true;
}
