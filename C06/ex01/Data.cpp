#include "Data.hpp"

Data::Data() : _value(0), _secondValue(0), _thirdValue(0) {}

Data::Data(int value, int secondValue, int thirdValue)
: _value(value)
, _secondValue(secondValue)
, _thirdValue(thirdValue) {}

Data::~Data() {}

Data::Data(const Data &other)
: _value(other._value)
, _secondValue(other._secondValue)
, _thirdValue(other._thirdValue) {}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		_value = other._value;
		_secondValue = other._secondValue;
		_thirdValue = other._thirdValue;
	}
	return *this;
}
