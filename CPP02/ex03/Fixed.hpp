/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:42:40 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 17:03:29 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	public:
	Fixed();
	Fixed(const Fixed& to_be_copied);
	Fixed(const int value);
	Fixed(const float value);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& n1, Fixed& n2);
	static Fixed& max(Fixed& n1, Fixed& n2);
	static const Fixed& min(const Fixed& n1, const Fixed&n2);
	static const Fixed& max(const Fixed& n1, const Fixed&n2);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int	toInt(void) const;

	private:
	int _value;
	const static int _bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_num);
#endif

//raw = real_value × 2^fractionalBits
//if _bits = 8, raw = real_value × 256