/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:28:49 by belinore          #+#    #+#             */
/*   Updated: 2026/05/12 17:28:52 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
//C is either std::vector<Item> or std::deque<Item>

template <typename C>
typename C::iterator PmergeMe::lowerBoundItems(typename C::iterator begin,
    typename C::iterator end,
    int value, size_t &counter)
{
    while (begin < end)
    {
        typename C::iterator mid = begin + (end - begin) / 2;
        if (mid->value < value)
            begin = mid + 1;
        else
            end = mid;
        counter++;
    }
    return begin;
}

template <typename C>
void buildJacobsthal(size_t size, C &j)
{
    j.push_back(0);
    j.push_back(1);
    while (j.back() < size)
    {
        size_t next = j[j.size() - 1] + 2 * j[j.size() - 2];
        j.push_back(next);
    }
}

template <typename C>
C insertionOrder(size_t size, C &jacobsthal)
{
    C order;
    C used(size, 0);

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
    return (order);
}

template <typename C>
void makePair(C &pairs, Item winner, Item pendant)
{
    Pair pair;
    pair.winner = winner;
    pair.pendant = pendant;
    pairs.push_back(pair);
}

template <typename C>
bool isSorted(const C &container)
{
    typename C::const_iterator it = container.begin();
    typename C::const_iterator next = it;
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

template <typename C>
void print_container(C &container, std::string prefix)
{
    if (!prefix.empty())
        std::cout << prefix;
    typename C::const_iterator it = container.begin();
    for (; it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
}

template <typename C>
void printPairs(const C &pairs, const std::string &prefix)
{
    if (!prefix.empty())
        std::cout << prefix << "\n";
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout << "Pair " << i << ": winner=" << pairs[i].winner.value
                  << ", id = " << pairs[i].winner.id
                  << ", pendant=" << pairs[i].pendant.value
                  << ", id = " << pairs[i].pendant.id << "\n";
    }
}

template <typename C>
void printItems(const C &items, const std::string &prefix)
{
    if (!prefix.empty())
        std::cout << prefix << "\n";
    for (size_t i = 0; i < items.size(); i++)
    {
        std::cout << "Item " << i << ": value=" << items[i].value
                  << ", id = " << items[i].id << "\n";
    }
}
