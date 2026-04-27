
#include "bigint.hpp"
#include <string>
#include <iostream>

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

bigint::
