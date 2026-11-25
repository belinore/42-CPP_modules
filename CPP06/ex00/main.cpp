/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:08:23 by belinore          #+#    #+#             */
/*   Updated: 2026/03/19 17:08:25 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "test_utils.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string value = argv[1];
		ScalarConverter::convert(value);
	}
	else
	{
		std::cerr << "Error: expected usage ./convert [value]\n";
		if (argc == 1)
		{
			if (get_yesno_input("Run default test cases? y/n"))
				test_examples();
		}
	}
	return (0);
}
