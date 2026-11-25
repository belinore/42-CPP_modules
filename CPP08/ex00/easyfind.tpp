/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:08:40 by belinore          #+#    #+#             */
/*   Updated: 2026/04/15 16:08:41 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int to_find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), to_find);
    if (it != container.end())
        return it;
    else
        throw std::runtime_error("Value not found in container");
}

template <typename T>
void test_easyfind(T &container, int to_find, std::string container_name)
{
    try
    {
        std::cout << "Searching for " << to_find << " in " << container_name << "\n";
        typename T::iterator it = easyfind(container, to_find);
        std::cout << "Success: Found "<< *it << "\n";
        print_container_from_iterator(container, it, container_name + " from iter: ");
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    } 
}

template <typename T>
void print_container_all(T &container, std::string prefix)
{
    if (!prefix.empty())
        std::cout << CYAN << prefix;
    typename T::iterator it = container.begin();
    for (; it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << "\n";
}

template <typename T>
void print_container_from_iterator(T &container, typename T::iterator it, std::string prefix)
{
    if (!prefix.empty())
        std::cout << prefix;
    try
    {
        for (; it != container.end(); it++)
            std::cout << *it << " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
}