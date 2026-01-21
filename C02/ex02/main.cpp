/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:42:46 by belinore          #+#    #+#             */
/*   Updated: 2026/01/21 19:42:46 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return (0);
// }

int main( void )
{
	Fixed a(5);
	Fixed b(2);

	std::cout << "Fixed numbers created:" << std::endl;
	std::cout << "\033[31m" << "a = " << a << std::endl;
	std::cout << "b = " << b << "\033[0m" << std::endl;

	std::cout << "\nTesting booleon operators:" << std::endl;
	std::cout << "\033[31m" << "a > b? " << (a > b) << std::endl;
	std::cout << "a < b? " << (a < b) << std::endl;
	std::cout << "a == b? " << (a == b) << std::endl;
	std::cout << "a != b? " << (a != b) << std::endl;
	std::cout << "a <= b? " << (a <= b) << std::endl;
	std::cout << "a >= b? " << (a >= b) << "\033[0m" << std::endl;

	Fixed c(2);
	std::cout << "Fixed number created:\n" << "\033[31m" << "c = " << c << std::endl;
	std::cout << "b == c? " << (b == c) << std::endl;
	std::cout << "b > c? " << (b > c) << std::endl;
	std::cout << "b < c? " << (b < c) << std::endl;
	std::cout << "b >= c? " << (b >= c) << std::endl;
	std::cout << "b <= c? " << (b >= c) << "\033[0m" << std::endl;

	std::cout << "\nTesting +-*/:" << std::endl;
	Fixed d;
	d = (a + b);
	std::cout << "Fixed number created:\n" << "\033[31m" << "d = a + b = " << d << "\033[0m" << std::endl;
	a = (a - b);
	std::cout << "Fixed number created:\n" << "\033[31m" << "a = a - b = " << a << "\033[0m" << std::endl;
	Fixed e(6);
	std::cout << "Fixed number created:\n" << "\033[31m" << "e = " << e << "\033[0m" << std::endl;
	e = e / a;
	std::cout << "\033[31m" << "e = e / a = " << e << "\033[0m" << std::endl;

	Fixed f = e * Fixed(10);
	std::cout << "\033[31m" << "f = e * Fixed(10)\nf = " << f << "\033[0m" << std::endl;
	++f;
	std::cout << "\033[31m" << "++f, f = " << f << "\033[0m" << std::endl;
	f++;
	std::cout << "\033[31m" << "f++, f = " << f << "\033[0m" << std::endl;
	--f;
	std::cout << "\033[31m" << "--f, f = " << f << "\033[0m" << std::endl;
	f--;
	std::cout << "\033[31m" << "f--, f = " << f << "\033[0m" << std::endl;
	Fixed i = 0;
	std::cout << "\nINCREMENT ++i starting i = " << i << std::endl;
	std::cout << "\033[31m" << "i = " << ++i << "\033[0m" << std::endl;
	std::cout << "\033[31m" << "i = " << ++i << "\033[0m" << std::endl;
	std::cout << "\033[31m" << "i = " << ++i << "\033[0m" << std::endl;

	std::cout << "\nINCREMENT i++ starting i = " << i << std::endl;
	i++;
	std::cout << "\033[31m" << "i = " << i << "\033[0m" << std::endl;
	i++;
	std::cout << "\033[31m" << "i = " << i << "\033[0m" << std::endl;
	i++;
	std::cout << "\033[31m" << "i = " << i << "\033[0m" << std::endl;

	std::cout << "\nDECREMENT --i, starting i = " << i << std::endl;
	std::cout << "\033[31m" << "i = " << --i << "\033[0m" << std::endl;
	std::cout << "\033[31m" << "i = " << --i << "\033[0m" << std::endl;
	std::cout << "\033[31m" << "i = " << --i << "\033[0m" << std::endl;

	std::cout << "\nDECREMENT i--, starting i = " << i << std::endl;
	i--;
	std::cout << "\033[31m" << "i = " << i << "\033[0m" << std::endl;
	i--;
	std::cout << "\033[31m" << "i = " << i << "\033[0m" << std::endl;
	i--;
	std::cout << "\033[31m" << "i = " << i << "\n" << "\033[0m" << std::endl;

	std::cout << "\nTesting MIN and MAX\n" << "\033[31m" << "b = " << b << "\n++c = " << ++c << "\033[0m" << std::endl;
	std::cout << "\033[31m" << "MIN of b and c is: " << Fixed::min(b, c) << "\033[0m" << std::endl;
	std::cout << "\033[31m" << "MAX of b and c is: " << Fixed::max(b, c) << "\n" << "\033[0m" << std::endl;
	return (0);
}