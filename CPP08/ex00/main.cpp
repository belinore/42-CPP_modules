/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:08:35 by belinore          #+#    #+#             */
/*   Updated: 2026/04/15 16:08:36 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

void print_vector_from_index(std::vector<int> &v, size_t start, size_t size)
{
	try
	{
		for (size_t i = start; i < size; i++)
			std::cout << v.at(i) << " ";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: Index out of range" << '\n';
	}
    std::cout << "\n";
}

void test_easyfind_vector(std::vector<int> &v, int to_find)
{
    try
    {
        std::cout << "Searching for " << to_find << "\n";
        std::vector<int>::iterator it = easyfind(v, to_find);
        std::cout << "Success: Found "<< *it << "\n";
        int index = std::distance(v.begin(), it);
        std::cout << "Vector from iter: ";
        print_vector_from_index(v, index, v.size());
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    } 
}

int main()
{
    //Vector
    std::vector<int> v;
    for (size_t i = 0; i < 10; i++)
		v.push_back(i);
    std::cout << CYAN << "Vector: ";
    print_vector_from_index(v, 0, v.size());
    std::cout << RESET;
    test_easyfind_vector(v, 5);
    test_easyfind_vector(v, 3);
    test_easyfind_vector(v, -1);
    std::cout << CYAN << "\nVector with template functions: \n" << RESET;
    test_easyfind(v, 0, "Vector");
    test_easyfind(v, 9, "Vector");
    test_easyfind(v, 15, "Vector");

    // //List
    std::list<int> l;
    for (size_t i = 0; i < 10; i++)
        l.push_back(i);
    print_container_all(l, CYAN "\nList: ");
    std::cout << RESET;
    test_easyfind(l, 2, "List");
    test_easyfind(l, -8, "List");

    // //Deque
    std::deque<int> d;
    for (size_t i = 0; i < 10; i++)
        d.push_back(i);
    std::string other = "other";
    print_container_all(d, CYAN "\nDeque: ");
    std::cout << RESET;
    test_easyfind(d, 3, "Deque");
    test_easyfind(d, -5, "Deque");
}

//a vector is a dynamic array - can add and remove elements from the back - can access any element by index - can be resized - can be sorted - can be iterated
//a queue is a first in first out data structure - can only add to the back and remove from the front
//a stack is a last in first out data structure - can only add and remove from the top
//a deque is a double ended queue - can add and remove from both ends - can be used as a stack or a queue. iteration is possible but not efficient -> can be sorted but not efficient
//a list is a doubly linked list - can add and remove elements from both ends - can access any element by index but it's not efficient - can be sorted - can be iterated
//a set is a collection of unique elements - can be sorted - can be iterated - can be used to check if an element exists in the set - can be used to find the intersection, union and difference of sets
//a map is a collection of key-value pairs - can be sorted by key - can be iterated - can be used to check if a key exists in the map - can be used to find the value associated with a key

//to learn later: unordered_set, unordered_map, bitset, pair and tuple
//a unordered_set is a collection of unique elements - can be iterated - can be used to check if an element exists in the set - can be used to find the intersection, union and difference of sets - not sorted
//an unordered_map is a collection of key-value pairs - can be iterated - can be used to check if a key exists in the map - can be used to find the value associated with a key - not sorted
//a bitset is a collection of bits - can be used to represent a set of boolean values - can be used to perform bitwise operations - can be iterated
//a pair is a collection of two values - can be used to store a pair of values - can be used to return multiple values from a function - can be iterated
//a tuple is a collection of multiple values - can be used to store multiple values - can be used to return multiple values from a function - can be iterated
