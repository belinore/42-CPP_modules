/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:22:26 by belinore          #+#    #+#             */
/*   Updated: 2026/03/19 19:22:28 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

int main()
{
	std::cout << "Test with INT\n";
	int a = 1;
	int b = 34;
	std::cout << "Before swap: a = " << a << " b = " << b << "\n";
	::swap(a, b);
	std::cout << "After swap: a = " << a << " b = " << b << "\n";
	std::cout << "min = " << ::min(a, b) << "\n";
	std::cout << "max = " << ::max(a, b) << "\n";

	std::cout << "\nTest with DOUBLE\n";
	double ad = 1.9879;
	double bd = 34.2364;
	std::cout << "Before swap: a = " << ad << " b = " << bd << "\n";
	::swap(ad, bd);
	std::cout << "After swap: a = " << ad << " b = " << bd << "\n";
	std::cout << "min = " << ::min(ad, bd) << "\n";
	std::cout << "max = " << ::max(ad, bd) << "\n";

	std::cout << "\nTest with STRING\n";
	std::string s1 = "Hello1";
	std::string s2 = "Hello2";
	std::cout << "Before swap: s1 = " << s1 << " s2 = " << s2 << "\n";
	::swap(s1, s2);
	std::cout << "After swap: s1 = " << s1 << " s2 = " << s2 << "\n";
	std::cout << "min = " << ::min(s1, s2) << "\n";
	std::cout << "max = " << ::max(s1, s2) << "\n";
}

// int main( void ) {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }