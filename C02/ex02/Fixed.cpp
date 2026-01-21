#include "Fixed.hpp"

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
	_value = roundf(value * (1 << _bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" <<std::endl;
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

	as_float = static_cast<float>(_value) / (1 << _bits);
	return (as_float);
}
	
int	Fixed::toInt(void) const
{
	int	as_int;

	as_int = _value >> _bits;
	return (as_int);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_num)
{
	os << fixed_num.toFloat();
	return (os);
}

/* 
ex02:
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
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed result;
    long temp = static_cast<long>(this->getRawBits() * other.getRawBits());
	result.setRawBits(temp >> _bits);
	return (result);
}

Fixed Fixed::operator/(const Fixed& other)
{
    Fixed result;
	long temp = static_cast<long>(this->getRawBits() << _bits);
	result.setRawBits(temp / other.getRawBits());
	return (result);
}

Fixed& Fixed::operator++()
{
	this->_value++;
    return (*this);
}

Fixed Fixed::operator++(int)
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