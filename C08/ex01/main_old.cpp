#define CYAN "\033[36m"
#define RESET "\033[0m"
#include "Span.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>

//Vectors
void gen_random_nbrs_vector(std::vector<int> &v, size_t size, int max_value)
{
	for (size_t i = 0; i < size; i++)
		v.push_back(rand() % max_value);
}

void print_vector_all(std::vector<int> &v, std::string prefix = "")
{
    if (!prefix.empty())
        std::cout << prefix;
	std::vector<int>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

void print_vector_from_iterator(std::vector<int> &v, std::vector<int>::iterator it)
{
    std::cout << "Vector from iterator: ";
    try
    {
        for (; it != v.end(); it++)
            std::cout << *it << " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
}

void print_vector(std::vector<int> &v, size_t start, size_t size)
{
	try
	{
		for (size_t i = start; i < size; i++)
			std::cout << v.at(i) << " ";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
}

//list
void gen_random_nbrs_list(std::list<int> &l, size_t size, int max_value)
{
    for (size_t i = 0; i < size; i++)
        l.push_back(rand() % max_value);
}

void print_list_all(std::list<int> &l, std::string prefix = "")
{
    if (!prefix.empty())
        std::cout << prefix;
    std::list<int>::iterator it = l.begin();
    for (; it != l.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

void example_of_stack()
{
    std::cout << "Stacks are LIFO\nPushing stack: [first in] ";
    std::stack<int> s;
    for (size_t i = 1; i < 10; i++)
    {
        s.push(i);
        std::cout << s.top() << " ";
    }
    std::cout << "[last in]\nPopping stack: [first out] ";
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "[last out]\n";
}

void example_of_queue()
{
    std::cout << "Queues are FIFO\nPushing queue: [first in] ";
    std::queue<int> q;
    for (size_t i = 1; i < 10; i++)
    {
        q.push(i);
        std::cout << q.back() << " ";
    }
    std::cout << "[last in]\nPopping queue: [first out] ";
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "[last out]\n";
}

void example_of_deque()
{
    std::cout << "Deques are double ended queues\nPushing deque: ";
    std::deque<int> d;
    for (size_t i = 1; i < 10; i++)
    {
        d.push_back(i);
        std::cout << d.back() << " ";
    }
    std::cout << "\nPopping deque from front: ";
    while (!d.empty())
    {
        std::cout << d.front() << " ";
        d.pop_front();
    }
    for (size_t i = 1; i < 10; i++)
        d.push_back(i);
    std::cout << "\nor Popping deque from back: ";
    while (!d.empty())
    {
        std::cout << d.back() << " ";
        d.pop_back();
    }
    std::cout << "\n";
}

int main()
{
	srand(time(NULL));
	//Vector
	std::vector<int> v;
	gen_random_nbrs_vector(v, 20, 50);
    print_vector_all(v, "v before sorting: ");
    std::sort(v.begin(), v.end());
    print_vector_all(v, "v after sorting : ");

    //list
    std::list<int> l;
    gen_random_nbrs_list(l, 20, 50);
    print_list_all(l, "l before sorting: ");
    l.sort();
    print_list_all(l, "l after sorting : ");

    //other containers
    // example_of_stack();
    // example_of_queue();
    // example_of_deque();
	
}

//a vector is a dynamic array - can add and remove elements from the back - can access any element by index - can be resized - can be sorted - can be iterated
//a queue is a first in first out data structure - can only add to the back and remove from the front
//a stack is a last in first out data structure - can only add and remove from the top
//a deque is a double ended queue - can add and remove from both ends - can be used as a stack or a queue
//a list is a doubly linked list - can add and remove elements from both ends - can access any element by index but it's not efficient - can be sorted - can be iterated
//a set is a collection of unique elements - can be sorted - can be iterated - can be used to check if an element exists in the set - can be used to find the intersection, union and difference of sets
//a map is a collection of key-value pairs - can be sorted by key - can be iterated - can be used to check if a key exists in the map - can be used to find the value associated with a key


//to learn later: unordered_set, unordered_map, bitset, pair and tuple
//a unordered_set is a collection of unique elements - can be iterated - can be used to check if an element exists in the set - can be used to find the intersection, union and difference of sets - not sorted
//an unordered_map is a collection of key-value pairs - can be iterated - can be used to check if a key exists in the map - can be used to find the value associated with a key - not sorted
//a bitset is a collection of bits - can be used to represent a set of boolean values - can be used to perform bitwise operations - can be iterated
//a pair is a collection of two values - can be used to store a pair of values - can be used to return multiple values from a function - can be iterated
//a tuple is a collection of multiple values - can be used to store multiple values - can be used to return multiple values from a function - can be iterated

// //queues add to back and pop from front - first in first out
// void gen_random_nbrs_queue(std::queue<int> &q, size_t size, int max_value)
// {
//     for (size_t i = 0; i < size; i++)
//     {
//         q.push(rand() % max_value);
//         std::cout << q.back() << " ";
//     }
//     std::cout << "\n";
// }

// //not possible to iterate - only the front and back elements are accessible
// //so only way to print is to pop elements from the front
// void print_and_empty_queue(std::queue<int> q)
// {
//     while (!q.empty())
//     {
//         std::cout << q.front() << " ";
//         q.pop();
//     }
//     std::cout << "\n";
// }

// void gen_random_nbrs_deque(std::deque<int> &d, size_t size, int max_value)
// {
//     for (size_t i = 0; i < size; i++)
//     {
//         d.push_back(rand() % max_value);
//         std::cout << d.back() << " ";
//     }
//     std::cout << "\n";
// }