/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:09:26 by belinore          #+#    #+#             */
/*   Updated: 2026/03/19 17:09:27 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <stdint.h>

class Data
{
	public:
	Data();
	Data(int value, int secondValue, int thirdValue);
	~Data();
	Data(const Data &);
	Data &operator=(const Data &);

	private:
	int _value;
	int _secondValue;
	int _thirdValue;
};


#endif