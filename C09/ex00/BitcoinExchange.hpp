/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:39:35 by belinore          #+#    #+#             */
/*   Updated: 2026/05/12 17:34:49 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>
#define MAX_YEAR 2026
#define MIN_YEAR 2009

class BitcoinExchange
{
    private:
    std::map<std::string, float> _exchangeRates;
    std::string _inputFile;
    std::string _lastDate;

    public:
    BitcoinExchange(std::string inputFile);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    void processInput();
    void printExchangeResult(const std::string &date, float value);

};

#endif