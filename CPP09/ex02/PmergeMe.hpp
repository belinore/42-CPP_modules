/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:29:53 by belinore          #+#    #+#             */
/*   Updated: 2026/05/13 16:11:40 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <ctime>

#define RANDOM_MAX 100
#define TEST_MODE 1
#define MAX_PRINT_SIZE 100
#define CYAN "\033[36m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

struct Item {
    int value;
    size_t id;
};

struct Pair {
    Item winner;
    Item pendant;
};

class PmergeMe
{
    private:
    std::vector<int> _vector;
    std::vector<int> _sortedVector;
    std::deque<int> _deque;
    std::deque<int> _sortedDeque;
    std::vector<size_t> _jacobsthal;
    std::deque<size_t> _jacobsthalDeque;
    size_t _size;
    clock_t _vectorTime;
    clock_t _dequeTime;
    size_t _comparisonCountVector;
    size_t _comparisonCountDeque;
    bool _processed;

    void sortVector();
    void sortVectorRecursive(std::vector<Item> &vector);
    void insertPendants_vec(std::vector<Item> &mainChain, std::vector<Item> &pendants, std::vector<size_t> &order, std::vector<Pair> &pairs);
    void insertStraggler_vec(std::vector<Item> &mainChain, Item &straggler);

    void sortDeque();
    void sortDequeRecursive(std::deque<Item> &deque);
    void insertPendants_deq(std::deque<Item> &mainChain, std::deque<Item> &pendants, std::deque<size_t> &order, std::deque<Pair> &pairs);
    void insertStraggler_deq(std::deque<Item> &mainChain, Item &straggler);

    void printResultsSimple() const;
    template <typename C>
    typename C::iterator lowerBoundItems(typename C::iterator begin, typename C::iterator end,
        int value, size_t &counter);
    template <typename T>
    void jacobsthalInsertionOrder(size_t size, T &order, T &jacobsthal);

    public:
    PmergeMe(int argc, char **argv);
    PmergeMe(size_t size);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    clock_t getVectorTime() const;
    clock_t getDequeTime() const;
    size_t getComparisonsVector() const;
    size_t getComparisonsDeque() const;

    void processInput(bool reprocess = false);
    void printResults() const;
    void printResultsDetails() const;
};

void assignWinnerPendant(Item &winner, Item &pendant, Item &valueA, Item &valueB);
Item makeItem(int value, size_t id);
template <typename C>
void buildJacobsthal(size_t size, C &j);
template <typename C>
C insertionOrder(size_t size, C &jacobsthal);
template <typename C>
void makePair(C &pairs, Item winner, Item pendant);
template <typename C>
bool isSorted(const C &container);
template <typename C>
void print_container(C &container, std::string prefix);
template <typename C>
void printPairs(const C &pairs, const std::string &prefix);
template <typename C>
void printItems(const C &items, const std::string &prefix);

#include "PmergeMe.tpp"

#endif
