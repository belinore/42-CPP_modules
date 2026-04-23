/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:57:36 by belinore          #+#    #+#             */
/*   Updated: 2026/04/23 19:35:59 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <deque>
#include <iostream>

#define RANDOM_MAX 100
#define TEST_MODE 0
#define USE_GENERIC 0
#define MAX_PRINT_SIZE 100
#define CYAN "\033[36m"
#define RESET "\033[0m"

class PmergeMe
{
    private:
    std::vector<int> _input;
    std::vector<int> _vector;
    std::vector<int> _sortedVector;
    std::deque<int> _deque;
    std::deque<int> _sortedDeque;
    std::list<int> _list;
    std::list<int> _sortedList;
    std::vector<size_t> _jacobsthal;
    std::deque<size_t> _jacobsthalDeque;
    size_t _size;
    clock_t _vectorTime;
    clock_t _listTime;
    clock_t _dequeTime;
    bool _processed;

    void printResultsSimple();
    void printResultsDetailed();
    void sortRecursiveVector(std::vector<int> &vector);
    void sortRecursiveDeque(std::deque<int> &deque);
    void sortRecursiveList(std::list<int> &list);
    template <typename T>
    void sortRecursive(T &container);
    template <typename T>
    void jacobsthalInsertionOrder(size_t size, T &order, T &jacobsthal);
    template <typename T, typename U>
    void insertPendants(T &mainChain, T &pendants, U &order, U &jacobsthal);
    template <typename T>
    void processInput_alt(T &unsorted, T &container, clock_t &time);

    public:
    PmergeMe(int argc, char **argv);
    PmergeMe(size_t size);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    clock_t getVectorTime() const;
    clock_t getListTime() const;
    clock_t getDequeTime() const;

    void processInput();
    void printResults();
};

//Generic version of the merge insertion sort algorithm, works with vector and deque
//but not list because it does not support random access operations. 
//Used when USE_GENERIC is set to 1
template <typename T>
void PmergeMe::sortRecursive(T &container)
{
    if (container.size() <= 1)
        return;
    T mainChain;
    T pendants;
    if (container.size() % 2 != 0)
        pendants.push_back(container.back());
    for (size_t i = 0; i < container.size() - 1; i += 2)
    {
        if (container[i] > container[i + 1])
        {   mainChain.push_back(container[i]);
            pendants.push_back(container[i + 1]);
        }
        else
        {
            mainChain.push_back(container[i + 1]);
            pendants.push_back(container[i]);
        }
    }
    if (mainChain.size() > 1)
        sortRecursive(mainChain);
    std::vector<size_t> order;
    insertPendants(mainChain, pendants, order, _jacobsthal);
    container = mainChain;
}

//order and jacobsthal will be either std::vector<size_t> or std::deque<size_t>
template <typename T>
void PmergeMe::jacobsthalInsertionOrder(size_t size, T &order, T &jacobsthal)
{
    T used(size, 0);

    size_t prev = 0;
    for (size_t i = 1; prev < size; i++)
    {
        size_t j = jacobsthal[i];
        if (j > size)
            j = size;
        for (size_t x = j; x > prev; x--)
        {
            if (!used[x - 1])
            {
                order.push_back(x - 1);
                used[x - 1] = 1;
            }
        }
        prev = j;
    }
}

template <typename T, typename U>
void PmergeMe::insertPendants(T &mainChain, T &pendants, U &order, U &jacobsthal)
{
    jacobsthalInsertionOrder(pendants.size(), order, jacobsthal);
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t idx = order[i];

        typename T::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), pendants[idx]);

        mainChain.insert(it, pendants[idx]);
    }
}

template <typename T>
void buildJacobsthal(size_t size, T &j)
{
    j.push_back(0);
    j.push_back(1);
    while (j.back() < size)
    {
        size_t next = j[j.size() - 1] + 2 * j[j.size() - 2];
        j.push_back(next);
    }
}

template <typename T>
void PmergeMe::processInput_alt(T &unsorted, T &container, clock_t &time)
{
    clock_t start = clock();
    container = unsorted;
    buildJacobsthal(_size, _jacobsthal);
    sortRecursive(container);
    clock_t end = clock();
    time = end - start;
}

template <typename T>
bool isSorted(const T &container)
{
    typename T::const_iterator it = container.begin();
    typename T::const_iterator next = it;
    if (it == container.end())
        return (true);
    next++;
    while (next != container.end())
    {
        if (*it > *next)
            return (false);
        it++;
        next++;
    }
    return (true);
}

template <typename T>
void print_container(T &container, std::string prefix)
{
    if (!prefix.empty())
        std::cout << prefix;
    typename T::iterator it = container.begin();
    for (; it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
}

#endif
