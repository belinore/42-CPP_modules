/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:25:06 by belinore          #+#    #+#             */
/*   Updated: 2026/03/20 14:16:05 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> arr1(5);
    for (unsigned int i = 0; i < arr1.size(); i++)
        arr1[i] = i + 1;
    std::cout << "arr1 : "; 
	try
	{
		for (unsigned int i = 0; i < arr1.size() + 1; i++)
			std::cout << arr1[i] << " ";
	}
	catch (...)
	{
		std::cout << "[Out of bounds exception caught]";
	}
    std::cout << "\n";
	Array<int> arr2(25);
	for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = i + 1;
	std::cout << "arr2 (before assignment): " << arr2 << "\n";
	Array<int> arr3(arr2);
	std::cout << "arr3 (copy constructed from arr2): " << arr3 << "\n";
	arr2 = arr1;
	std::cout << "arr2 (after assignment to arr1): " << arr2 << "\n";
	std::cout << "arr3 (unchanged): " << arr3 << "\n";
	Array<char> arr4(2);
	arr4[0] = 'H';
	arr4[1] = 'i';
	std::cout << "arr4 : " << arr4 << "\n";
	Array<Array<int>*> arr_arr(2);
	arr_arr[0] = &arr1;
	arr_arr[1] = &arr2;
	std::cout << "arr_arr ptrs: " << arr_arr << "\n";
}
