/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortDeque.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:30:11 by belinore          #+#    #+#             */
/*   Updated: 2026/05/12 17:30:12 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::sortDeque()
{
    if (_processed || _size == 0 || _deque.empty())
        return ;
    clock_t start = clock();
    buildJacobsthal(_size, _jacobsthalDeque);
    std::deque<Item> mainChain;
    for (size_t i = 0; i < _deque.size(); i++)
    {
        Item item = makeItem(_deque[i], i);
        mainChain.push_back(item);
    }
    sortDequeRecursive(mainChain);
    _sortedDeque.clear();
    for (size_t i = 0; i < mainChain.size(); i++)
        _sortedDeque.push_back(mainChain[i].value);
    clock_t end = clock();
    _dequeTime = end - start;
}

void PmergeMe::sortDequeRecursive(std::deque<Item> &items)
{
    if (items.size() <= 1)
        return ;
    Item straggler = makeItem(-1, 0);
    if (items.size() % 2 != 0)
        straggler = items.back();
    std::deque<Item> mainChain;
    std::deque<Item> pendants;
    std::deque<Pair> pairs;
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
    sortDequeRecursive(mainChain);
    std::deque<size_t> order = insertionOrder(pairs.size(), _jacobsthalDeque);
    insertPendants_deq(mainChain, pendants, order, pairs);
    if (straggler.value >= 0)
        insertStraggler_deq(mainChain, straggler);
    items = mainChain;
}

void PmergeMe::insertPendants_deq(std::deque<Item> &mainChain, std::deque<Item> &pendants, std::deque<size_t> &order, std::deque<Pair> &pairs)
{       
    std::deque<size_t> winnerPos(_size, 0);
    for (size_t i = 0; i < pendants.size(); i++)
        winnerPos[mainChain[i].id] = i;
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t i_jac = order[i];
        Item pendant = pendants[i_jac];
        Pair pInfo = pairs[i_jac];
        size_t wPos = winnerPos[pInfo.winner.id];
        std::deque<Item>::iterator end = mainChain.begin() + wPos + 1;
        std::deque<Item>::iterator it =
            lowerBoundItems<std::deque<Item> >(mainChain.begin(), end, pendant.value, _comparisonCountDeque);
        size_t insertPos = it - mainChain.begin();
        mainChain.insert(it, pendants[i_jac]);
        for (size_t j = 0; j < winnerPos.size(); j++)
        {
            if (winnerPos[j] >= insertPos)
                winnerPos[j]++;
        }
    }
}

void PmergeMe::insertStraggler_deq(std::deque<Item> &mainChain, Item &straggler)
{
    if (straggler.value < 0)
        return ;
    std::deque<Item>::iterator it =
        lowerBoundItems<std::deque<Item> >(mainChain.begin(), mainChain.end(), straggler.value, _comparisonCountDeque);
    mainChain.insert(it, straggler);
}
