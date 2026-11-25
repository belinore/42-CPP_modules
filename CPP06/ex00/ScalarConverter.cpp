/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:08:27 by belinore          #+#    #+#             */
/*   Updated: 2026/03/19 17:08:28 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

void ScalarConverter::convert(const std::string &literal)
{
	double value;
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		value = static_cast<double>(literal[0]);
	else
	{
		char *end;
		value = std::strtod(literal.c_str(), &end);
		if (invalidInput(end))
			return ;
	}
	printChar(value);
	printInt(value);
	std::cout << std::fixed << std::setprecision(1);
	printFloat(value);
	printDouble(value);
}

void ScalarConverter::printChar(double value)
{
	if (value >= 32 && value <= 126)
	{
		char value_c = static_cast<char>(value);
		std::cout << "char: '" << value_c << "'\n";
	}
	else if (value <= std::numeric_limits<char>::max() && 
			 value >= std::numeric_limits<char>::min())
		std::cout << "char: non-displayable\n";
	else
		std::cout << "char: impossible\n";
}

void ScalarConverter::printInt(double value)
{
	if (value > std::numeric_limits<int>::max() ||
		value < std::numeric_limits<int>::min() || std::isnan(value))
		std::cout << "int: impossible\n";
	else
	{
		int value_int = static_cast<int>(value);
		std::cout << "int: " << value_int << "\n";
	}
}

void ScalarConverter::printFloat(double value)
{
	float value_f = static_cast<float>(value);
	std::cout << "float: " << value_f << "f\n";
}

void ScalarConverter::printDouble(double value)
{
	std::cout << "double: " << value << "\n";
}

bool ScalarConverter::invalidInput(char *end)
{
	bool is_float = false;
	
	if (end[0] == 'f' && end[1] == '\0')
		is_float = true;
	if (*end != '\0' && !is_float)
	{
		std::cout << "Char: Impossible\n" 
				  << "Int: Impossible\n"
				  << "Float: Impossible\n"
				  << "Double: Impossible\n";
		return (true);
	}
	return (false);
}
