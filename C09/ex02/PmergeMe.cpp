/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:29:27 by belinore          #+#    #+#             */
/*   Updated: 2026/05/12 17:29:29 by belinore         ###   ########.fr       */
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

PmergeMe::PmergeMe(int argc, char **argv) : _comparisonCountVector(0), _comparisonCountDeque(0), _processed(false)
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
        _deque.push_back(num);
    }
    _size = _vector.size();

}

PmergeMe::PmergeMe(size_t size) : _comparisonCountVector(0), _comparisonCountDeque(0), _processed(false)
{
    if (size == 0)
        throw std::invalid_argument("Size must be greater than 0");
    for (size_t i = 0; i < size; i++)
    {
        int num = rand() % RANDOM_MAX;
        _vector.push_back(num);
        _deque.push_back(num);
    }
    _size = size;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
: _vector(other._vector), _deque(other._deque), _jacobsthal(other._jacobsthal)
, _jacobsthalDeque(other._jacobsthalDeque), _size(other._size), _comparisonCountVector(other._comparisonCountVector)
, _comparisonCountDeque(other._comparisonCountDeque), _processed (other._processed)
{
    if (other._processed)
    {
        _sortedVector = other._sortedVector;
        _sortedDeque = other._sortedDeque;
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
    }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
        _jacobsthal = other._jacobsthal;
        _jacobsthalDeque = other._jacobsthalDeque;
        _size = other._size;
        _processed = other._processed;
        _comparisonCountVector = other._comparisonCountVector;
        _comparisonCountDeque = other._comparisonCountDeque;
        if (other._processed)
        {
            _sortedVector = other._sortedVector;
            _sortedDeque = other._sortedDeque;
            _vectorTime = other._vectorTime;
            _dequeTime = other._dequeTime;
        }
    }
    return (*this);
}

void PmergeMe::printResults() const
{
    if (!_processed)
    {
        print_container(_vector, "Unsorted numbers: ");
        std::cout << "Call processInput() to sort\n";
        return ;
    }
    if (!TEST_MODE)
    {
        printResultsSimple();
        return ;
    }
    if (_vector.size() <= MAX_PRINT_SIZE)
    {
        std::cout << CYAN << "Vector: \n" << RESET;
        print_container(_vector, "Before: ");
        print_container(_sortedVector, "After: ");
        std::cout << CYAN << "Deque: \n" << RESET;
        print_container(_deque, "Before: ");
        print_container(_sortedDeque, "After: ");
        std::cout << "\n";
    }
    printResultsDetails();
}

void PmergeMe::printResultsDetails() const
{
    std::cout << "Clock ticks: Vector -> " << _vectorTime
                << ", Deque -> " << _dequeTime << " ";
    if (_vectorTime > _dequeTime)
        std::cout << "(deque faster by " << (_vectorTime - _dequeTime) << " clock ticks)\n";
    else if (_dequeTime > _vectorTime)
        std::cout << "(vector faster by " << (_dequeTime - _vectorTime) << " clock ticks)\n";
    else
        std::cout << "(vector and deque have the same time)\n";
    std::cout << "Comparisons: Vector -> " << _comparisonCountVector
                << ", Deque -> " << _comparisonCountDeque << "\n";
    std::cout << "Is Sorted? : Vector -> " << (isSorted(_sortedVector) ? GREEN "YES" : RED "NO")
              << RESET << ", Deque -> " << (isSorted(_sortedDeque) ? GREEN "YES" : RED "NO") 
              << RESET << "\n\n";
}

void PmergeMe::printResultsSimple() const
{
    print_container(_vector, "Before: ");
    print_container(_sortedVector, "After: ");
    double vectorTimeMicro = static_cast<double>(_vectorTime) / CLOCKS_PER_SEC * 1000000.0;
    double dequeTimeMicro = static_cast<double>(_dequeTime) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector : " << _vectorTime << " clock ticks "
              << "(" << std::fixed << std::setprecision(5) << vectorTimeMicro << " us)\n";
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << _dequeTime << " clock ticks "
              << "(" << std::fixed << std::setprecision(5) << dequeTimeMicro << " us)\n";
}

void PmergeMe::processInput(bool reprocess)
{
    if (_processed && reprocess)
    {
        _comparisonCountVector = 0;
        _comparisonCountDeque = 0;
        _vectorTime = 0;
        _dequeTime = 0;
        _sortedVector.clear();
        _sortedDeque.clear();
        _processed = false;
    }
    sortVector();
    sortDeque();
    _processed = true;
}

clock_t PmergeMe::getVectorTime() const { return (_vectorTime); }

clock_t PmergeMe::getDequeTime() const { return (_dequeTime); }

size_t PmergeMe::getComparisonsVector() const { return (_comparisonCountVector); }

size_t PmergeMe::getComparisonsDeque() const { return (_comparisonCountDeque); }
