/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:29:59 by belinore          #+#    #+#             */
/*   Updated: 2026/05/12 17:30:01 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

Item makeItem(int value, size_t id)
{
    Item item;
    item.value = value;
    item.id = id;
    return (item);
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
    if (_processed || _vector.empty() || _size == 0)
        return ;
    clock_t start = clock();
    buildJacobsthal(_size, _jacobsthal);
    std::vector<Item> mainChain;
    for (size_t i = 0; i < _vector.size(); i++)
    {
        Item item = makeItem(_vector[i], i);
        mainChain.push_back(item);
    }
    sortVectorRecursive(mainChain);
    _sortedVector.clear();
    for (size_t i = 0; i < mainChain.size(); i++)
        _sortedVector.push_back(mainChain[i].value);
    clock_t end = clock();
    _vectorTime = end - start;
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
    insertPendants_vec(mainChain, pendants, order, pairs);
    if (straggler.value >= 0)
        insertStraggler_vec(mainChain, straggler);
    items = mainChain;
}

void PmergeMe::insertPendants_vec(std::vector<Item> &mainChain, std::vector<Item> &pendants, std::vector<size_t> &order, std::vector<Pair> &pairs)
{       
    std::vector<size_t> winnerPos(_size, 0);
    for (size_t i = 0; i < pendants.size(); i++)
        winnerPos[mainChain[i].id] = i;
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t i_jac = order[i];
        Item pendant = pendants[i_jac];
        Pair pInfo = pairs[i_jac];
        size_t wPos = winnerPos[pInfo.winner.id];
        std::vector<Item>::iterator end = mainChain.begin() + wPos + 1;
        std::vector<Item>::iterator it =
            lowerBoundItems<std::vector<Item> >(mainChain.begin(), end, pendant.value, _comparisonCountVector);
        size_t insertPos = it - mainChain.begin();
        mainChain.insert(it, pendants[i_jac]);
        for (size_t j = 0; j < winnerPos.size(); j++)
        {
            if (winnerPos[j] >= insertPos)
                winnerPos[j]++;
        }
    }
}

void PmergeMe::insertStraggler_vec(std::vector<Item> &mainChain, Item &straggler)
{
    if (straggler.value < 0)
        return ;
    std::vector<Item>::iterator it =
        lowerBoundItems<std::vector<Item> >(mainChain.begin(), mainChain.end(), straggler.value, _comparisonCountVector);
    mainChain.insert(it, straggler);
}


