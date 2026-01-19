/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:26:27 by belinore          #+#    #+#             */
/*   Updated: 2026/01/19 12:49:41 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i]; i++)
	{
		std::string str_arg(argv[i]);
		for (std::size_t j = 0; j < str_arg.length(); j++)
			str_arg[j] = static_cast<char>(std::toupper(static_cast<unsigned char>(str_arg[j])));
		std::cout << str_arg;
		if (argv[i + 1])
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
