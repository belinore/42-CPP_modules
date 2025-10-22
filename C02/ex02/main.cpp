#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}

// int main( void )
// {
// 	Fixed a(5);
// 	Fixed b(2);
	
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;

// 	std::cout << "a > b? " << (a > b) << std::endl;
// 	std::cout << "a < b? " << (a < b) << std::endl;
// 	std::cout << "a == b? " << (a == b) << std::endl;
// 	std::cout << "a != b? " << (a != b) << std::endl;
// 	std::cout << "a <= b? " << (a <= b) << std::endl;
// 	std::cout << "a >= b? " << (a >= b) << std::endl;

// 	Fixed c(2);
// 	std::cout << "b == c? " << (b == c) << std::endl;
// 	std::cout << "b > c? " << (b > c) << std::endl;
// 	std::cout << "b < c? " << (b < c) << std::endl;
// 	std::cout << "b >= c? " << (b >= c) << std::endl;
// 	std::cout << "b <= c? " << (b >= c) << std::endl;

// 	Fixed d;
// 	d = (a + b);
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;
// 	std::cout << "d = a + b, d = " << d << std::endl;
// 	a = (a - b);
// 	std::cout << "a = a - b, a = " << a << std::endl;
// 	Fixed e(6);
// 	std::cout << "e = " << e << " | a = " << a << std::endl;
// 	e = e / a;
// 	std::cout << "e = e / a, e = " << e << std::endl;
// 	Fixed f = e * Fixed(10);
// 	std::cout << "f = e * Fixed(10), f = " << f << std::endl;
// 	++f;
// 	std::cout << "++f, f = " << f << std::endl;
// 	f++;
// 	std::cout << "f++, f = " << f << std::endl;
// 	--f;
// 	std::cout << "--f, f = " << f << std::endl;
// 	f--;
// 	std::cout << "f--, f = " << f << std::endl;
// 	//test for increments/decrements
// 	Fixed i;
// 	std::cout << "INCREMENT ++i, i initialized to " << i << std::endl;
// 	while (i < 5)
// 		std::cout << "i = " << ++i << std::endl;
// 	i = 0;
// 	std::cout << "INCREMENT i++, i initialized to " << i << std::endl;
// 	while (i < 5)
// 		std::cout << "i = " << i++ << std::endl;
// 	std::cout << "DECREMENT --i, i = " << i << std::endl;
// 	while (i > 0)
// 		std::cout << "i = " << --i << std::endl;
// 	i = 5;
// 	std::cout << "DECREMENT i--, i = " << i << std::endl;
// 	while (i > 0)
// 		std::cout << "i = " << i-- << std::endl;
// 	Fixed g;
// 	g--;
// 	std::cout << Fixed::min( a, g ) << std::endl;
// 	return (0);
// }