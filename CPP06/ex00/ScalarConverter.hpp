/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:09:06 by belinore          #+#    #+#             */
/*   Updated: 2026/03/19 17:09:07 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALERCONVERTER_CPP
# define SCALERCONVERTER_CPP

#include <string>

class ScalarConverter
{
	public:
	static void convert(const std::string &literal);

	private:
	static void printChar(double value);
	static void printInt(double value);
	static void printFloat(double value);
	static void printDouble(double value);
	static bool invalidInput(char *end);

	ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();
};

#endif
