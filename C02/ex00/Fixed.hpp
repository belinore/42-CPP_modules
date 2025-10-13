#include <iostream>

class Fixed
{
	public:
	Fixed(); //default constructor
	Fixed(const Fixed& to_be_copied); //copy constructor
	Fixed& operator=(const Fixed& other); //copy assignment??
	~Fixed(); //destructor

	int getRawBits(void) const;
	void setRawBits(int const raw);

	private:
	int _value;
	const static int _bits = 8;
};