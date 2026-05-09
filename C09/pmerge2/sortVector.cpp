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

std::vector<Pair>::iterator PmergeMe::lowerBoundPairs(
    std::vector<Pair>::iterator begin,
    std::vector<Pair>::iterator end,
    int value)
{
    while (begin < end)
    {
        std::vector<Pair>::iterator mid = begin + (end - begin) / 2;
        if (mid->winner < value)
            begin = mid + 1;
        else
            end = mid;
        _comparisonCountVector++;
    }
    return begin;
}

void PmergeMe::insertFinal(std::vector<Pair> &pairs, std::vector<size_t> &order)
{
    // start with the sorted winners
    _sortedVector.clear();
    for (size_t i = 0; i < pairs.size(); i++)
        _sortedVector.push_back(pairs[i].winner);
    // track where each winner currently sits — starts at its index
    std::vector<size_t> winnerPos(pairs.size());
    for (size_t i = 0; i < pairs.size(); i++)
        winnerPos[pairs[i].id] = i;
    // update winner positions as we insert pendants
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t i_jac = order[i];
        Pair pendant = pairs[i_jac];
        size_t wPos = winnerPos[pendant.id];
        std::vector<int>::iterator end = _sortedVector.begin() + wPos + 1;
        std::vector<int>::iterator it = lowerBoundCount(_sortedVector.begin(), end, pendant.pendant);
        size_t insertPos = it - _sortedVector.begin();
        _sortedVector.insert(it, pendant.pendant);
        // update winner positions
        for (size_t j = 0; j < winnerPos.size(); j++)
        {
            if (winnerPos[j] >= insertPos)
                winnerPos[j]++;
        }
    }
}

void makePairVector(std::vector<Pair> &pairs, int winner, int pendant, int w_id, int p_id)
{
    Pair pair;
    pair.winner = winner;
    pair.pendant = pendant;
    pair.id = w_id;
    pair.id2 = p_id;
    pairs.push_back(pair);
}

void printPairs(const std::vector<Pair> &pairs, const std::string &prefix)
{
    if (!prefix.empty())
        std::cout << prefix << "\n";
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout << "Pair " << i << ": winner=" << pairs[i].winner
                  << ", pendant=" << pairs[i].pendant
                  << ", id=" << pairs[i].id
                    << ", index=" << pairs[i].index << "\n";
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
    if (straggler > -1)
        std::cout << "Straggler: " << straggler << "\n";
    //divide into pairs and put larger in main chain and smaller in pendants
    std::vector<Pair> pairs;
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        if (_vector[i] > _vector[i + 1])
        {
            makePairVector(pairs, _vector[i], _vector[i + 1], i / 2, i / 2);
        }
        else
        {
            makePairVector(pairs, _vector[i + 1], _vector[i], i / 2, i / 2);
        }
    }
    printPairs(pairs, "Initial pairs:");
    std::vector<Pair> mainChain = pairs;
    sortVectorRecursive(mainChain);
    printPairs(mainChain, "Sorted pairs:");
    std::vector<size_t> order;
    jacobsthalInsertionOrder(pairs.size(), order, _jacobsthal);
    insertFinal(mainChain, order);
    if (straggler > -1)
    {
        std::vector<int>::iterator it =
        std::lower_bound(_sortedVector.begin(), _sortedVector.end(), straggler);
        _sortedVector.insert(it, straggler);
    }
    print_container(_sortedVector, "Final sorted vector: ");
}

void PmergeMe::insertPendants(std::vector<Pair> &mainChain, std::vector<Pair> &pendants, std::vector<size_t> &order, std::vector<Pair> &pairs)
{       
    std::cout << "Original pairings:\n";
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout << "Pair " << i << ": winner=" << pairs[i].winner
                  << ", id = " << pairs[i].id
                  << ", pendant=" << pairs[i].pendant
                   << ", id2 = " << pairs[i].id2 << "\n";
    }
    std::vector<Pair> winners = mainChain;
    std::vector<size_t> winnerPos(_size, 0);
    for (size_t i = 0; i < pendants.size(); i++)
    {
        winnerPos[mainChain[i].id] = i;
    }
    print_container(winnerPos, "winnerPos: ");
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t i_jac = order[i];
        Pair pendant = pendants[i_jac];
        Pair pendantInfo = pairs[i_jac];
        size_t wPos = winnerPos[pendantInfo.id];
        std::cout << "order[" << i << "] = i_jac " << i_jac << " (inserting pendant " << pendant.winner
                  << " associated with winner " << mainChain[wPos].winner << " with id " << pendantInfo.id << " wpos " << wPos << ")\n";
        std::vector<Pair>::iterator end = mainChain.begin() + wPos + 1;
        std::vector<Pair>::iterator it =
            lowerBoundPairs(mainChain.begin(), end, pendant.winner);
        size_t insertPos = it - mainChain.begin();
        mainChain.insert(it, pendants[i_jac]);
        std::cout << "Inserted pendant " << pendant.winner << " at position " << insertPos << "\n";
        for (size_t j = 0; j < winnerPos.size(); j++)
        {
            if (winnerPos[j] >= insertPos)
            {
                std::cout << "Updating winnerPos for id " << j << " from " << winnerPos[j] << " to " << winnerPos[j] + 1 << "\n";
                winnerPos[j]++;
            }
                
        }
    }
}

void PmergeMe::sortVectorRecursive(std::vector<Pair> &vector)
{
    if (vector.size() <= 1)
    {
        std::cout << "Base case reached with vector size " << vector.size() << "\n\n";
        return ;
    }
    bool hasStraggler = false;
    Pair straggler;
    if (vector.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = vector.back();
        std::cout << "Straggler in recursive call: winner=" << straggler.winner
                  << ", pendant=" << straggler.pendant
                  << ", id=" << straggler.id << "\n";
    }
    std::vector<Pair> mainChain;
    std::vector<Pair> pendants;
    std::vector<Pair> pairs;
    for (size_t i = 0; i + 1 < vector.size(); i += 2)
    {
        if (vector[i].winner > vector[i + 1].winner)
        {  
            mainChain.push_back(vector[i]);
            pendants.push_back(vector[i + 1]);
            makePairVector(pairs, vector[i].winner, vector[i + 1].winner, vector[i].id, vector[i + 1].id);
        }
        else
        {
            mainChain.push_back(vector[i + 1]);
            pendants.push_back(vector[i]);
            makePairVector(pairs, vector[i + 1].winner, vector[i].winner, vector[i + 1].id, vector[i].id);
        }
        mainChain.back().index = i / 2;
        pendants.back().index = i / 2;
    }
    printPairs(mainChain, "REC Main chain before sorting:");
    sortVectorRecursive(mainChain);
    printPairs(mainChain, "REC Main chain after sorting:");
    printPairs(pendants, "REC Pendants to be inserted:");
    //insertion
    std::vector<size_t> order;
    jacobsthalInsertionOrder(pendants.size(), order, _jacobsthal);
    print_container(order, "Insertion order (Jacobsthal sequence): ");
    insertPendants(mainChain, pendants, order, pairs);
    if (hasStraggler)
    {
        std::cout << "Inserting straggler into main chain: " << straggler.winner << "\n";
        std::vector<Pair>::iterator it =
        lowerBoundPairs(mainChain.begin(), mainChain.end(), straggler.winner);
        mainChain.insert(it, straggler);
    }
    printPairs(mainChain, "REC Main chain after inserting pendants:");
    vector = mainChain;
}
