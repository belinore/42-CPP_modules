/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:43:16 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 18:48:27 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {};

Point::Point(const float x, const float y) : _x(x), _y(y) {};

Point::~Point() {};

Point::Point(const Point& other)
{
	*this = other;
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		std::cerr << "\033[31m" << "Error: Cannot assign to const members _x and _y"
		          << "\033[0m" << std::endl;
	}
	return (*this);
}

const Fixed& Point::getX() const
{
	return (_x);
}

const Fixed& Point::getY() const
{
	return (_y);
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << "(" << point.getX().toFloat() << ", " << point.getY().toFloat() << ")";
	return (os);
}

