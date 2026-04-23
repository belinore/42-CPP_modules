/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:39:35 by belinore          #+#    #+#             */
/*   Updated: 2026/04/23 14:12:40 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

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
    float getExchangeRate(const std::string &date);
};

template <typename T>
typename T::iterator easyfind(T& container, int to_find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), to_find);
    if (it != container.end())
        return it;
    else
        throw std::runtime_error("Value not found in container");
}

#endif