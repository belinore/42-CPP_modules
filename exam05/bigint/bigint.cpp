
#include "bigint.hpp"
#include <string>
#include <iostream>

bigint::bigint() : _nbr("0") {}

bigint::bigint(unsigned int nbr) : _nbr(std::to_string(nbr)) {}

bigint::bigint(std::string nbr) : _nbr(nbr) {}

bigint::bigint(const bigint &other) : _nbr(other._nbr) {}

bigint &bigint::operator=(const bigint &other)
{
    if (this != &other)
    {
        this->_nbr = other._nbr;
    }
    return (*this);
}

bigint::~bigint() {}

bigint bigint::operator+(const bigint &other) const
{
    std::string result;
    int carry = 0;
    int len1 = this->_nbr.length();
    int len2 = other._nbr.length();
    int maxLength = std::max(len1, len2);

    for (int i = 0; i < maxLength || carry; ++i)
    {
        int sum = carry;
        if (i < this->_nbr.length())
            sum += this->_nbr[this->_nbr.length() - 1 - i] - '0';
        if (i < other._nbr.length())
            sum += other._nbr[other._nbr.length() - 1 - i] - '0';
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    std::reverse(result.begin(), result.end());
    return (bigint(result));
}

bigint &bigint::operator+=(const bigint &other)
{
    *this = *this + other;
    return (*this);
}

bigint bigint::operator++(int)
{
    bigint temp(*this);
    *this += bigint(1);
    return (temp);
}

bigint &bigint::operator++()
{
    *this += bigint(1);
    return (*this);
}

bigint bigint::operator<<(unsigned int shift)
{
    std::string result = this->_nbr;
    result.append(shift, '0');
    return (bigint(result));
}

bigint &bigint::operator<<=(unsigned int shift)
{
    *this = *this << shift;
    return (*this);
}

bigint bigint::operator>>(unsigned int shift)
{
    if (shift >= this->_nbr.length())
        return (bigint(0));
    return (bigint(this->_nbr.substr(0, this->_nbr.length() - shift)));
}

bigint &bigint::operator>>=(unsigned int shift)
{
    *this = *this >> shift;
    return (*this);
}

bigint &bigint::operator>>=(const bigint &shift)
{
    double shiftValue = std::stod(shift.get_nbr());
    unsigned int shiftInt = static_cast<unsigned int>(shiftValue);
    return (*this >>= shiftValue);
}

std::ostream &operator<<(std::ostream &os, const bigint &nbr)
{
    os << nbr.get_nbr();
    return (os);
}

std::string bigint::get_nbr() const
{
    return (this->_nbr);
}

bool bigint::operator<(const bigint &other) const
{
    if (this->_nbr.length() != other._nbr.length())
        return (this->_nbr.length() < other._nbr.length());
    return (this->_nbr < other._nbr);
}

bool bigint::operator>(const bigint &other) const
{
    return (other < *this);
}

bool bigint::operator==(const bigint &other) const
{
    return (this->_nbr == other._nbr);
}

bool bigint::operator!=(const bigint &other) const
{
    return (!(*this == other));
}

bool bigint::operator<=(const bigint &other) const
{
    return (*this < other || *this == other);
}

bool bigint::operator>=(const bigint &other) const
{
    return (*this > other || *this == other);
}
