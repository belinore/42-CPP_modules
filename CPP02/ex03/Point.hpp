/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:43:21 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 18:50:29 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <ostream>

class Point
{
	public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();

	const Fixed& getX() const;
	const Fixed& getY() const;

	private:
	Fixed const _x;
	Fixed const _y;
};

std::ostream& operator<<(std::ostream& os, const Point& point);

#endif