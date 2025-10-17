#include <iostream>
#include <cmath>

class Fixed
{
	public:
	Fixed();
	Fixed(const Fixed& to_be_copied);
	Fixed(const int value);
	Fixed(const float value);
	Fixed& operator=(const Fixed& other);
	bool operator>(const Fixed& other);
	bool operator<(const Fixed& other);
	bool operator>=(const Fixed& other);
	bool operator<=(const Fixed& other);
	bool operator==(const Fixed& other);
	bool operator!=(const Fixed& other);

	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);

	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int	toInt(void) const;

	private:
	int _value;
	const static int _bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_num);