#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_num)
{
	os << fixed_num.toFloat();
	return (os);
}

int	Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	float as_float;

	as_float = (float)_value / (1 << _bits);
	return (as_float);
}
	
int	Fixed::toInt(void) const
{
	int	as_int;

	as_int = _value >> _bits;
	return (as_int);
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed& to_be_copied)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_be_copied;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" <<std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _bits));//to understand better!!!!!!!
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" <<std::endl;
}

/* ex02:
Add public member functions to your class to overload the following operators:
• The 6 comparison operators: >, <, >=, <=, ==, and !=.
• The 4 arithmetic operators: +, -, *, and /.
• The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, which will increase or decrease the fixed-point value by
the smallest representable ϵ, such that 1 + ϵ > 1.
Add these four public overloaded member functions to your class:
• A static member function min that takes two references to fixed-point numbers as
parameters, and returns a reference to the smallest one.
• A static member function min that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the smallest one.
• A static member function max that takes two references to fixed-point numbers as
parameters, and returns a reference to the greatest one.
• A static member function max that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the greatest one.
*/

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed& other)
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other)
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other)
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other)
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++() //prefix
{
	this->_value++;
    return (*this);
}

Fixed Fixed::operator++(int) //postfix
{
	Fixed temp(*this);
	this->_value++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return (temp);
}

Fixed& Fixed::min(Fixed& n1, Fixed& n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}
Fixed& Fixed::max(Fixed& n1, Fixed& n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}
const Fixed& Fixed::min(const Fixed& n1, const Fixed&n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}
const Fixed& Fixed::max(const Fixed& n1, const Fixed&n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}