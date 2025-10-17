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
	
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << "a > b? " << (a > b) << std::endl;
	std::cout << "a < b? " << (a < b) << std::endl;
	std::cout << "a == b? " << (a == b) << std::endl;
	std::cout << "a != b? " << (a != b) << std::endl;
	std::cout << "a <= b? " << (a <= b) << std::endl;
	std::cout << "a >= b? " << (a >= b) << std::endl;

	Fixed c(2);
	std::cout << "b == c? " << (b == c) << std::endl;
	std::cout << "b > c? " << (b > c) << std::endl;
	std::cout << "b < c? " << (b < c) << std::endl;
	std::cout << "b >= c? " << (b >= c) << std::endl;
	std::cout << "b <= c? " << (b >= c) << std::endl;

	Fixed d;
	d = a + b;
	std::cout << "c = a + b, c = " << a << std::endl;

	return (0);
}