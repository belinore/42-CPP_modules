#include <algorithm>
#include <vector>
#include <cstddef>

class PmergeMe
{
public:
    void sortRecursiveVector(std::vector<int> &vec);

private:
    struct Item
    {
        int         value;
        std::size_t  id;
    };

    struct PairInfo
    {
        Item        big;
        Item        small;
        std::size_t pairId;
    };

    std::vector<std::size_t> _jacobsthal;

    void buildJacobsthal(std::size_t size);
    void jacobsthalInsertionOrder(std::size_t size,
                                  std::vector<std::size_t> &order);

    void sortRecursiveItems(std::vector<Item> &items);
};

static bool operator<(const PmergeMe::Item &a, const PmergeMe::Item &b)
{
    return (a.value < b.value);
}

void PmergeMe::buildJacobsthal(std::size_t size)
{
    _jacobsthal.clear();
    _jacobsthal.push_back(0);
    _jacobsthal.push_back(1);
    while (_jacobsthal.back() < size)
    {
        std::size_t next;
        next = _jacobsthal[_jacobsthal.size() - 1]
             + 2 * _jacobsthal[_jacobsthal.size() - 2];
        _jacobsthal.push_back(next);
    }
}

void PmergeMe::jacobsthalInsertionOrder(std::size_t size,
                                        std::vector<std::size_t> &order)
{
    std::vector<char> used;
    std::size_t       prev;
    std::size_t       i;
    std::size_t       j;

    order.clear();
    if (size == 0)
        return;
    used.assign(size, 0);
    prev = 0;
    i = 1;
    while (prev < size)
    {
        j = _jacobsthal[i];
        if (j > size)
            j = size;
        while (j > prev)
        {
            if (!used[j - 1])
            {
                order.push_back(j - 1);
                used[j - 1] = 1;
            }
            --j;
        }
        prev = _jacobsthal[i];
        if (prev > size)
            prev = size;
        ++i;
    }
}

void PmergeMe::sortRecursiveItems(std::vector<Item> &items)
{
    if (items.size() <= 1)
        return;

    std::vector<PairInfo>      pairsById;
    std::vector<Item>          winners;
    std::vector<Item>          chain;
    std::vector<std::size_t>   pairOfItemId;
    std::vector<std::size_t>   bigPos;
    std::vector<std::size_t>   order;
    bool                       hasOdd;
    Item                       odd;
    std::size_t                i;

    hasOdd = (items.size() % 2 != 0);
    if (hasOdd)
        odd = items.back();

    pairsById.reserve(items.size() / 2);
    winners.reserve(items.size() / 2 + 1);
    pairOfItemId.assign(items.size(), 0);

    i = 0;
    while (i + 1 < items.size())
    {
        PairInfo p;

        p.pairId = pairsById.size();
        if (items[i].value >= items[i + 1].value)
        {
            p.big = items[i];
            p.small = items[i + 1];
        }
        else
        {
            p.big = items[i + 1];
            p.small = items[i];
        }
        pairsById.push_back(p);
        winners.push_back(p.big);
        pairOfItemId[p.big.id] = p.pairId;
        ++i;
        ++i;
    }

    if (winners.size() > 1)
        sortRecursiveItems(winners);

    chain.reserve(items.size());
    bigPos.resize(pairsById.size());
    i = 0;
    while (i < winners.size())
    {
        std::size_t pairId;

        pairId = pairOfItemId[winners[i].id];
        chain.push_back(pairsById[pairId].big);
        bigPos[i] = i;
        ++i;
    }

    buildJacobsthal(pairsById.size());
    jacobsthalInsertionOrder(pairsById.size(), order);

    i = 0;
    while (i < order.size())
    {
        std::size_t idx;
        std::vector<Item>::iterator it;
        std::vector<Item>::iterator end;
        std::size_t insertPos;
        std::size_t j;

        idx = order[i];
        end = chain.begin() + bigPos[idx];
        it = std::lower_bound(chain.begin(), end, pairsById[idx].small);
        insertPos = static_cast<std::size_t>(it - chain.begin());
        chain.insert(it, pairsById[idx].small);

        j = 0;
        while (j < bigPos.size())
        {
            if (bigPos[j] >= insertPos)
                ++bigPos[j];
            ++j;
        }
        ++i;
    }

    if (hasOdd)
    {
        std::vector<Item>::iterator it;

        it = std::lower_bound(chain.begin(), chain.end(), odd);
        chain.insert(it, odd);
    }

    items = chain;
}

void PmergeMe::sortRecursiveVector(std::vector<int> &vec)
{
    std::vector<Item> items;
    std::size_t       i;

    items.reserve(vec.size());
    i = 0;
    while (i < vec.size())
    {
        Item item;

        item.value = vec[i];
        item.id = i;
        items.push_back(item);
        ++i;
    }

    sortRecursiveItems(items);

    vec.clear();
    i = 0;
    while (i < items.size())
    {
        vec.push_back(items[i].value);
        ++i;
    }
}