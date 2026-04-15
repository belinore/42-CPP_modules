#include "PmergeMe.hpp"
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe(int argc, char **argv)
{
    if (!argv && TEST_MODE)
    {
        for (int i = 0; i < argc; i++)
        {
            int num = rand() % RANDOM_MAX;
            _vector.push_back(num);
            _list.push_back(num);
            _deque.push_back(num);
        }
        return ;
    }
    else if (!argv)
        throw std::invalid_argument("No arguments provided");
    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]);
        if (arg.empty())
            throw std::invalid_argument("Empty arguments are not allowed");
        int num = std::atoi(argv[i]);
        if (num < 0)
            throw std::invalid_argument("Negative numbers are not allowed: " + std::string(argv[i]));
        _vector.push_back(num);
        _list.push_back(num);
        _deque.push_back(num);
    }
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _list(other._list), _deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _list = other._list;
        _deque = other._deque;
    }
    return (*this);
}

void printVector(std::vector<int> &vector, std::string prefix)
{
    if (!prefix.empty())
        std::cout << prefix;
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << vector[i] << " ";
    std::cout << "\n";
}

void printDeque(std::deque<int> &deque, std::string prefix)
{
    if (!prefix.empty())
        std::cout << prefix;
    for (size_t i = 0; i < deque.size(); i++)
        std::cout << deque[i] << " ";
    std::cout << "\n";
}

void printList(std::list<int> &list, std::string prefix)
{
    if (!prefix.empty())
        std::cout << prefix;
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
}

void sortRecursiveVector(std::vector<int> &vector)
{
    if (vector.size() <= 1)
        return;
    std::vector<int> mainChain;
    std::vector<int> pendants;
    for (size_t i = 0; i < vector.size(); i += 2)
    {
        if (i + 1 < vector.size())
        {
            if (vector[i] > vector[i + 1])
            {   mainChain.push_back(vector[i]);
                pendants.push_back(vector[i + 1]);
            }
            else
            {
                mainChain.push_back(vector[i + 1]);
                pendants.push_back(vector[i]);
            }
        }
        else
        {
            pendants.push_back(vector[i]);
        }
    }
    if (mainChain.size() > 1)
        sortRecursiveVector(mainChain);
    for (size_t i = 0; i < pendants.size(); i++)
    {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendants[i]);
        mainChain.insert(it, pendants[i]);
    }
    vector = mainChain;
}

void sortRecursiveDeque(std::deque<int> &deque)
{
    if (deque.size() <= 1)
        return;
    std::deque<int> mainChain;
    std::deque<int> pendants;
    for (size_t i = 0; i < deque.size(); i += 2)
    {
        if (i + 1 < deque.size())
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
        else
        {
            pendants.push_back(deque[i]);
        }
    }
    if (mainChain.size() > 1)
        sortRecursiveDeque(mainChain);
    for (size_t i = 0; i < pendants.size(); i++)
    {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendants[i]);
        mainChain.insert(it, pendants[i]);
    }
    deque = mainChain;
}

void sortRecursiveList(std::list<int> &list)
{
    if (list.size() <= 1)
        return;
    std::list<int> mainChain;
    std::list<int> pendants;
    for (std::list<int>::iterator it = list.begin(); it != list.end(); )
    {
        std::list<int>::iterator next = std::next(it);
        if (next != list.end())
        {
            if (*it > *next)
            {   mainChain.push_back(*it);
                pendants.push_back(*next);
            }
            else
            {
                mainChain.push_back(*next);
                pendants.push_back(*it);
            }
            it = std::next(next);
        }
        else
        {
            pendants.push_back(*it);
            break;
        }
    }
    if (mainChain.size() > 1)
        sortRecursiveList(mainChain);
    for (std::list<int>::iterator it = pendants.begin(); it != pendants.end(); it++)
    {
        std::list<int>::iterator insertIt = std::lower_bound(mainChain.begin(), mainChain.end(), *it);
        mainChain.insert(insertIt, *it);
    }
    list = mainChain;
}

void PmergeMe::processInput()
{
    
    _sortedVector = _vector;
    clock_t start = clock();
    sortRecursiveVector(_sortedVector);
    clock_t end = clock();
    double elapsed = double(end - start);
    // printVector(_vector, "Original vector: ");
    // printVector(_sortedVector, "Sorted vector: ");
    std::cout << "Is sorted?: " << (isSorted(_sortedVector) ? "Yes" : "No") << "\n";
    std::cout << "Time taken to sort vector: " << elapsed << " clock ticks\n";

    _sortedDeque = _deque;
    start = clock();
    sortRecursiveDeque(_sortedDeque);
    end = clock();
    elapsed = double(end - start);
    // printDeque(_deque, "Original deque: ");
    // printDeque(_sortedDeque, "Sorted deque: ");
    std::cout << "Is sorted?: " << (isSorted(_sortedDeque) ? "Yes" : "No") << "\n";
    std::cout << "Time taken to sort deque: " << elapsed << " clock ticks\n";

    _sortedList = _list;
    start = clock();
    sortRecursiveList(_sortedList);
    end = clock();
    elapsed = double(end - start);
    // printList(_list, "Original list: ");
    // printList(_sortedList, "Sorted list: ");
    std::cout << "Is sorted?: " << (isSorted(_sortedList) ? "Yes" : "No") << "\n";
    std::cout << "Time taken to sort list: " << elapsed << " clock ticks\n";

}

template <typename T>
bool PmergeMe::isSorted(const T& container)
{
    return (std::is_sorted(container.begin(), container.end()));
}

