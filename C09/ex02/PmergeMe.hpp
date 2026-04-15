#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <deque>

#define RANDOM_MAX 100
#define TEST_MODE 1

class PmergeMe
{
    private:
    std::vector<int> _vector;
    std::vector<int> _sortedVector;
    std::list<int> _list;
    std::list<int> _sortedList;
    std::deque<int> _deque;
    std::deque<int> _sortedDeque;

    public:
    PmergeMe(int argc, char **argv);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    void processInput();
    template <typename T>
    bool isSorted(const T& container);
};

void printVector(std::vector<int> &vector, std::string prefix);

#endif
