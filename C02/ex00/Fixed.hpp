#include <iostream>

class Fixed
{
	public:
	Fixed();
	Fixed(Fixed to_be_copied);
	int getRawBits(void) const;
	void setRawBits(int const raw);

	private:
	int before_decimal;
	const static int after_decimal = 8;
}