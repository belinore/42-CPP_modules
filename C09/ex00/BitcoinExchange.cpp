/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:39:40 by belinore          #+#    #+#             */
/*   Updated: 2026/05/13 16:06:41 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

template <typename T>
void print_map(T &map, std::string prefix = "")
{
    if (!prefix.empty())
        std::cout << prefix << "\n";
    for (typename T::iterator it = map.begin(); it != map.end(); it++)
        std::cout << it->first << ": " << std::setprecision(2)
                  << std::fixed << it->second << "\n";
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
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
: _exchangeRates(other._exchangeRates), _inputFile(other._inputFile) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _exchangeRates = other._exchangeRates;
        _inputFile = other._inputFile;
    }
    return (*this);
}

static int strtoi(const std::string &nbr)
{
    char *end;
    long value = std::strtol(nbr.c_str(), &end, 10);
    if (*end != '\0')
        throw std::invalid_argument("Invalid number: " + nbr);
    if (value > std::numeric_limits<int>::max())
        throw std::invalid_argument("Too large");
    return (value);
}

static void validateDate(const std::string &date, const std::string &line)
{
    if ((date.size() != 10 && !(date.size() == 11 && date[10] == ' '))
        || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("bad input => " + line);
    long year = strtoi(date.substr(0, 4).c_str());
    long month = strtoi(date.substr(5, 2).c_str());
    long day = strtoi(date.substr(8, 2).c_str());
    if (year > MAX_YEAR || year < MIN_YEAR)
        throw std::runtime_error("bad input => " + line);
    if (month < 1 || month > 12)
        throw std::runtime_error("bad input => " + line);
    if (day < 1 || day > 31)
        throw std::runtime_error("bad input => " + line);
    bool isLeap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    if ((month == 2 && day > 29) || (month == 2 && day == 29 && !isLeap)) 
        throw std::runtime_error("bad input => " + line);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::runtime_error("bad input => " + line);
}

void BitcoinExchange::printExchangeResult(const std::string &date, float value)
{
    std::map<std::string, float>::iterator it = _exchangeRates.lower_bound(date);
    if (it == _exchangeRates.begin() && it->first > date)
        throw std::runtime_error("no exchange rate available for date " + date);
    else if (it == _exchangeRates.end() || it->first != date)
        it--;
    float rate = it->second;
    std::cout << date << " => " << value << " = " << std::setprecision(2)
              << std::fixed << value * rate << "\n";
    if (date > _exchangeRates.rbegin()->first)
        std::cout << "Warning: used last available exchange rate in database : " 
                  << _exchangeRates.rbegin()->first << '\n';
}

static void parseLine(const std::string &line, std::string &date, float &value)
{
    std::stringstream ss(line);
    if (!(std::getline(ss, date, '|')))
        throw std::runtime_error("bad input => " + line);
    date.erase(date.find_last_not_of(" \t") + 1);
    validateDate(date, line);
    std::string nbr;
    char *end;
    if (!(std::getline(ss, nbr)))
        throw std::runtime_error("bad input => " + line);
    nbr.erase(nbr.find_last_not_of(" \t") + 1);
    value = strtof(nbr.c_str(), &end);
    if (*end != '\0')
        throw std::runtime_error("bad input => " + line);
}

void BitcoinExchange::processInput()
{
    std::ifstream input(_inputFile.c_str());
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
            if (line.empty())
                continue ;
            std::string date;
            float value;
            parseLine(line, date, value);
            if (value <= 0)
                throw std::out_of_range("not a positive number");
            if (value > 1000)
                throw std::out_of_range("number too large");
            printExchangeResult(date, value);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}

