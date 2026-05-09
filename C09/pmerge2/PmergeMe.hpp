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

struct Pair {
    int winner;
    int pendant;
    size_t id;   // THIS is the key
    size_t id2;
    size_t index;
};

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
    int _comparisonCountVector;

    void printResultsSimple();
    void printResultsDetailed();
    
    void sortVector();
    void sortVectorRecursive(std::vector<Pair> &vector);

    void insertFinal(std::vector<Pair> &pairs, std::vector<size_t> &order);
    void insertPendants(std::vector<Pair> &mainChain, std::vector<Pair> &pendants, std::vector<size_t> &order, std::vector<Pair> &pairs);
    std::vector<int>::iterator lowerBoundCount(std::vector<int>::iterator begin, 
    std::vector<int>::iterator end, int value);
    std::vector<Pair>::iterator lowerBoundPairs(std::vector<Pair>::iterator begin,
        std::vector<Pair>::iterator end, int value);
    // void sortRecursiveDeque(std::deque<int> &deque);
    // void sortRecursiveList(std::list<int> &list);
    // template <typename T>
    // void sortRecursive(T &container);
    template <typename T>
    void jacobsthalInsertionOrder(size_t size, T &order, T &jacobsthal);
    // template <typename T, typename U>
    // void insertPendants(T &mainChain, T &pendants, U &order, U &jacobsthal);
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

// template <typename T>
// void PmergeMe::processInput_alt(T &unsorted, T &container, clock_t &time)
// {
//     clock_t start = clock();
//     container = unsorted;
//     buildJacobsthal(_size, _jacobsthal);
//     sortRecursive(container);
//     clock_t end = clock();
//     time = end - start;
// }

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
