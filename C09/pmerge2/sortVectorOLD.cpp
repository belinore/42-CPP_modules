#include "PmergeMe.hpp"

std::vector<int>::iterator PmergeMe::lowerBoundCount(std::vector<int>::iterator begin, 
    std::vector<int>::iterator end, int value)
{
    while (begin < end)
    {
        std::vector<int>::iterator mid = begin + (end - begin) / 2;
        if (*mid < value)
            begin = mid + 1;
        else
            end = mid;
        _comparisonCountVector++;
    }
    return begin;
}

void PmergeMe::insertFinal(std::vector<std::pair<int,int> > &pairs, std::vector<size_t> &order, int straggler)
{
    // start with the sorted winners
    _sortedVector.clear();
    for (size_t i = 0; i < pairs.size(); i++)
        _sortedVector.push_back(pairs[i].first);
    // track where each winner currently sits — starts at its index
    std::vector<size_t> winnerPos(pairs.size());
    for (size_t i = 0; i < pairs.size(); i++)
        winnerPos[i] = i;
    // update winner positions as we insert pendants
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t idx = order[i];
        std::vector<int>::iterator end = _sortedVector.begin() + winnerPos[idx];
        std::vector<int>::iterator it = lowerBoundCount(_sortedVector.begin(), end, pairs[idx].second);
        _sortedVector.insert(it, pairs[idx].second);
        // update winner positions
        size_t insertPos = it - _sortedVector.begin();
        for (size_t j = 0; j < winnerPos.size(); j++)
        {
            if (winnerPos[j] >= insertPos)
                winnerPos[j]++;
        }
    }
     if (straggler > -1)
    {
        std::vector<int>::iterator it =
            lowerBoundCount(_sortedVector.begin(), _sortedVector.end(), straggler);
        _sortedVector.insert(it, straggler);
    }
}

void PmergeMe::sortVector()
{
    _sortedVector.clear();
    if (_vector.size() <= 1)
    {
        _sortedVector = _vector;
        return ;
    }
    //handle straggler
    int straggler = -1;
    if (_vector.size() % 2 != 0)
        straggler = _vector.back();
    //divide into pairs and put larger in main chain and smaller in pendants
    std::vector<std::pair<int,int> > pairs;
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        if (_vector[i] > _vector[i + 1])
            pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
        else
            pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
    }
    sortVectorRecursive(pairs);
    std::vector<size_t> order;
    jacobsthalInsertionOrder(pairs.size(), order, _jacobsthal);
    insertFinal(pairs, order, straggler);
}

void PmergeMe::insertPendants(std::vector<std::pair<int,int> > &mainChain, std::vector<std::pair<int,int> > &pendants, std::vector<size_t> &order, std::vector<size_t> &winnerPos)
{    
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t idx = order[i];
        std::vector<std::pair<int,int> >::iterator end = mainChain.begin() + winnerPos[idx];
        std::vector<std::pair<int,int> >::iterator it =
            lowerBoundPairs(mainChain.begin(), end, pendants[idx].first);
        mainChain.insert(it, pendants[idx]);
        size_t insertPos = it - mainChain.begin();
        for (size_t j = 0; j < winnerPos.size(); j++)
        {
            if (winnerPos[j] >= insertPos)
                winnerPos[j]++;
        }
    }
    if (pendants.size() > order.size())
    {
        std::vector<std::pair<int,int> >::iterator it =
            lowerBoundPairs(mainChain.begin(), mainChain.end(), pendants.back().first);
        mainChain.insert(it, pendants.back());
    }
}

std::vector<std::pair<int,int> >::iterator PmergeMe::lowerBoundPairs(
    std::vector<std::pair<int,int> >::iterator begin,
    std::vector<std::pair<int,int> >::iterator end,
    int value)
{
    while (begin < end)
    {
        std::vector<std::pair<int,int> >::iterator mid = begin + (end - begin) / 2;
        if (mid->first < value)
            begin = mid + 1;
        else
            end = mid;
        _comparisonCountVector++;
    }
    return begin;
}

void PmergeMe::sortVectorRecursive(std::vector<std::pair<int,int> > &vector)
{
    //base case: if the vector has 0 or 1 elements, it's already sorted
    if (vector.size() <= 1)
        return;
    //handle straggler
    bool hasStraggler = false;
    std::pair<int,int> straggler;
    if (vector.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = vector.back();
    }
    std::vector<std::pair<int,int> > mainChain;
    std::vector<std::pair<int,int> > pendants;
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
    std::vector<int> pairedWinners;
    for (size_t i = 0; i < pendants.size(); i++)
        pairedWinners.push_back(mainChain[i].first);

    sortVectorRecursive(mainChain);

    std::vector<size_t> winnerPos(pendants.size());
    for (size_t i = 0; i < pendants.size(); i++)
    {
        std::vector<std::pair<int,int> >::iterator it =
            lowerBoundPairs(mainChain.begin(), mainChain.end(), pairedWinners[i]);
        winnerPos[i] = it - mainChain.begin();
    }

    std::vector<size_t> order;
    jacobsthalInsertionOrder(pendants.size(), order, _jacobsthal);
    if (hasStraggler)
        pendants.push_back(straggler);
    insertPendants(mainChain, pendants, order, winnerPos);
    vector = mainChain;
}
