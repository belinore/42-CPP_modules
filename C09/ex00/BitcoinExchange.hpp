#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
    private:
    std::map<std::string, float> _exchangeRates;
    std::string _inputFile;

    public:
    BitcoinExchange(std::string inputFile);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    void processInput();
};

#endif