#ifndef DATA_HPP
#define DATA_HPP

#include <cstdint>

class Data
{
	public:
	Data();
	Data(int value, int secondValue, int thirdValue);
	~Data();
	Data(const Data &);
	Data &operator=(const Data &);

	private:
	int _value;
	int _secondValue;
	int _thirdValue;
};


#endif