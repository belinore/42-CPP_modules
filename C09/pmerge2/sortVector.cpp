#include "PmergeMe.hpp"

std::vector<Item>::iterator PmergeMe::lowerBoundItems(std::vector<Item>::iterator begin,
    std::vector<Item>::iterator end,
    int value)
{
    while (begin < end)
    {
        std::vector<Item>::iterator mid = begin + (end - begin) / 2;
        if (mid->value < value)
            begin = mid + 1;
        else
            end = mid;
        _comparisonCountVector++;
    }
    return begin;
}

Item makeItem(int value, size_t id)
{
    Item item;
    item.value = value;
    item.id = id;
    return (item);
}

void PmergeMe::insertStraggler(std::vector<Item> &mainChain, Item &straggler)
{
    if (straggler.value < 0)
        return ;
    std::vector<Item>::iterator it =
        lowerBoundItems(mainChain.begin(), mainChain.end(), straggler.value);
    mainChain.insert(it, straggler);
}

void assignWinnerPendant(Item &winner, Item &pendant, Item &valueA, Item &valueB)
{
    if (valueA.value > valueB.value)
    {
        winner = valueA;
        pendant = valueB;
    }
    else
    {
        winner =  valueB;
        pendant = valueA;
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
    Item straggler = makeItem(-1, 0);
    if (_vector.size() % 2 != 0)
        straggler = makeItem(_vector.back(), _vector.size() - 1);
    std::vector<Pair> pairs;
    std::vector<Item> mainChain;
    std::vector<Item> pendants;
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        Item ItemA = makeItem(_vector[i], i);
        Item ItemB = makeItem(_vector[i + 1], i + 1);
        Item winner, pendant;
        assignWinnerPendant(winner, pendant, ItemA, ItemB);
        makePair(pairs, winner, pendant);
        mainChain.push_back(winner);
        pendants.push_back(pendant);
    }
    sortVectorRecursive(mainChain);
    std::vector<size_t> order = insertionOrder(pairs.size(), _jacobsthal);
    insertPendants(mainChain, pendants, order, pairs);
    if (straggler.value >= 0)
        insertStraggler(mainChain, straggler);
    for (size_t i = 0; i < mainChain.size(); i++)
        _sortedVector.push_back(mainChain[i].value);
}

void PmergeMe::insertPendants(std::vector<Item> &mainChain, std::vector<Item> &pendants, std::vector<size_t> &order, std::vector<Pair> &pairs)
{       
    //printPairs(pairs, "Original Pairs for pendant insertion:");
    std::vector<size_t> winnerPos(_size, 0);
    for (size_t i = 0; i < pendants.size(); i++)
    {
        winnerPos[mainChain[i].id] = i;
    }
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t i_jac = order[i];
        Item pendant = pendants[i_jac];
        Pair pInfo = pairs[i_jac];
        size_t wPos = winnerPos[pInfo.winner.id];
        // std::cout << "order[" << i << "] = i_jac " << i_jac << " (inserting pendant " << pendant.value
        //           << " associated with winner " << mainChain[wPos].value << " with id " << pInfo.winner.id << " wpos " << wPos << ")\n";
        std::vector<Item>::iterator end = mainChain.begin() + wPos + 1;
        std::vector<Item>::iterator it =
            lowerBoundItems(mainChain.begin(), end, pendant.value);
        size_t insertPos = it - mainChain.begin();
        mainChain.insert(it, pendants[i_jac]);
        // std::cout << "Inserted pendant " << pendant.value << " at position " << insertPos << "\n";
        for (size_t j = 0; j < winnerPos.size(); j++)
        {
            if (winnerPos[j] >= insertPos)
                winnerPos[j]++;
        }
    }
}

void PmergeMe::sortVectorRecursive(std::vector<Item> &items)
{
    if (items.size() <= 1)
        return ;
    Item straggler = makeItem(-1, 0);
    if (items.size() % 2 != 0)
        straggler = items.back();
    std::vector<Item> mainChain;
    std::vector<Item> pendants;
    std::vector<Pair> pairs;
    for (size_t i = 0; i + 1 < items.size(); i += 2)
    {
        Item itemA = makeItem(items[i].value, items[i].id);
        Item itemB = makeItem(items[i + 1].value, items[i + 1].id);
        Item winner, pendant;
        assignWinnerPendant(winner, pendant, itemA, itemB);
        makePair(pairs, winner, pendant);
        mainChain.push_back(winner);
        pendants.push_back(pendant);
    }
    sortVectorRecursive(mainChain);
    std::vector<size_t> order = insertionOrder(pairs.size(), _jacobsthal);
    insertPendants(mainChain, pendants, order, pairs);
    if (straggler.value >= 0)
        insertStraggler(mainChain, straggler);
    items = mainChain;
}
