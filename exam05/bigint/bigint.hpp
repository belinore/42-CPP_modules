#pragma once

#include <iostream>

class bigint
{
    private:
    std::string _nbr;

    public:
    bigint(unsigned int nbr);
    bigint(std::string nbr);
    bigint(const bigint &other);
    bigint &operator=(const bigint &other);
    ~bigint();

    bigint &operator+(const bigint &other);
}