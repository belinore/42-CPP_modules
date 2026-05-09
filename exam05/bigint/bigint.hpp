#pragma once

#include <iostream>

class bigint
{
    private:
    std::string _nbr;

    public:
    bigint();
    bigint(unsigned int nbr);
    bigint(std::string nbr);
    bigint(const bigint &other);
    bigint &operator=(const bigint &other);
    ~bigint();
    std::string get_nbr() const;

    bigint operator+(const bigint &other) const;
    bigint &operator+=(const bigint &other);
    bigint operator++(int);
    bigint &operator++();
    bigint operator<<(unsigned int shift);
    bigint &operator<<=(unsigned int shift);
    bigint operator>>(unsigned int shift);
    bigint &operator>>=(unsigned int shift);
    bigint &operator>>=(const bigint &shift);
    bool operator<(const bigint &other) const;
    bool operator>(const bigint &other) const;
    bool operator==(const bigint &other) const;
    bool operator!=(const bigint &other) const;
    bool operator<=(const bigint &other) const;
    bool operator>=(const bigint &other) const;
    

};

std::ostream &operator<<(std::ostream &os, const bigint &nbr);
