#include "BitcoinExchange.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange(std::string inputFile) : _inputFile(inputFile)
{
    std::ifstream data("data.csv");
    if (!data.is_open())
        throw std::runtime_error("Error: could not open data.csv");
    _exchangeRates.clear();
    std::string line;
    std::getline(data, line);
    if (line.find("date,exchange_rate") == std::string::npos)
        throw std::runtime_error("Error: invalid data.csv format");
    int i = 0;
    while (std::getline(data, line))
    {
        std::stringstream ss(line);
        std::string date;
        float rate;
        if (std::getline(ss, date, ',') && ss >> rate)
            _exchangeRates[date] = rate;
        else if (!line.empty())
            throw std::runtime_error("Error: invalid data.csv format");
    }
    // while (std::getline(data, line))
    // {
    //     size_t sep = line.find(',');
    //     if (sep != std::string::npos)
    //     {
    //         std::string date = line.substr(0, sep);
    //         float rate = std::stof(line.substr(sep + 1));
    //         _exchangeRates[date] = rate;
    //     }
    //     else if (!line.empty())
    //         throw std::runtime_error("Error: invalid data.csv format");
    // }
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _exchangeRates(other._exchangeRates), _inputFile(other._inputFile) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _exchangeRates = other._exchangeRates;
        _inputFile = other._inputFile;
    }
    return (*this);
}

void BitcoinExchange::processInput()
{
    // std::ifstream input(_inputFile);
    // if (!input.is_open())
    //     throw std::runtime_error("Error: could not open inputFile");
    // std::string line;
    // std::string sep = " | ";
    // std::getline(input, line, sep)

    // For each line, parse the date and value
    // Look up the exchange rate for the date in _exchangeRates
    // Calculate the equivalent value in Bitcoin and print it
}
