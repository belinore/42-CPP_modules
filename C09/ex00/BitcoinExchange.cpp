#include "BitcoinExchange.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>

template <typename T>
void print_map(T &map, std::string prefix = "")
{
    if (!prefix.empty())
        std::cout << prefix << "\n";
    for (typename T::iterator it = map.begin(); it != map.end(); it++)
        std::cout << it->first << ": " << std::setprecision(2) << std::fixed << it->second << "\n";
}

BitcoinExchange::BitcoinExchange(std::string inputFile) : _inputFile(inputFile)
{
    std::ifstream data("data.csv");
    if (!data.is_open())
        throw std::runtime_error("could not open data.csv");
    _exchangeRates.clear();
    std::string line;
    std::getline(data, line);
    if (line.find("date,exchange_rate") == std::string::npos)
        throw std::runtime_error("invalid data.csv format");
    while (std::getline(data, line))
    {
        std::stringstream ss(line);
        std::string date;
        float rate;
        if (std::getline(ss, date, ',') && ss >> rate)
            _exchangeRates[date] = rate;
        else if (!line.empty())
            throw std::runtime_error("invalid data.csv format");
    }
    std::cout << "Loaded : " << _exchangeRates.size() << " exchange rates from data.csv\n";
    //print_map(_exchangeRates, "Exchange rates:");
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

static bool isValidDate(const std::string &date)
{
    if ((date.size() != 10 && !(date.size() == 11 && date[10] == ' '))
        || date[4] != '-' || date[7] != '-')
        return (false);
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return (false);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return (false);
    }
    return (true);
}

static void processLine(const std::string &line, std::map<std::string, float> &exchangeRates)
{
    if (line.empty())
        return;
    std::stringstream ss(line);
    std::string date;
    float value;
    if (!(std::getline(ss, date, '|')) || !isValidDate(date) || !(ss >> value))
        throw std::runtime_error("bad input => " + line);
    if (value <= 0)
        throw std::out_of_range("not a positive number");
    if (value > 1000)
        throw std::out_of_range("number too large");
    date = date.erase(date.find_last_not_of(" \t") + 1);
    std::map<std::string, float>::iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.begin() && it->first > date)
        throw std::runtime_error("no exchange rate available for date " + date);
    else if (it == exchangeRates.end() || it->first != date)
        it--;
    std::cout << date << " => " << value << " = " << value * it->second << "\n";
    //std::cout << "Using exchange rate from " << it->first << ": " << std::setprecision(2) << std::fixed << it->second << "\n";
}

void BitcoinExchange::processInput()
{
    std::multimap<std::string, float> data;
    std::ifstream input(_inputFile);
    if (!input.is_open())
        throw std::runtime_error("could not open inputFile");
    std::string line;
    std::getline(input, line);
    if (line != "date | value")
        throw std::runtime_error("invalid input file format");
    while (std::getline(input, line))
    {
        try 
        {
            processLine(line, _exchangeRates);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}

