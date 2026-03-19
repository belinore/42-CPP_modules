/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:25:06 by belinore          #+#    #+#             */
/*   Updated: 2026/03/19 19:25:07 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i + 1;
    std::cout << "Integer Array: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << intArray[i] << " ";
    std::cout << "\n";
}