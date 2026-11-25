/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:42:46 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 18:49:04 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void print_result(bool result)
{
	if (result)
		std::cout << "\033[1m" << "Point is INSIDE the triangle\n"
		          << "\033[0m" << std::endl;
	else
		std::cout << "\033[1m" << "Point is OUTSIDE the triangle\n"
		          << "\033[0m" << std::endl;
}

int main( void )
{
	//Point inside triangle:
	print_result(bsp( Point(0, 0), Point(5, 0), Point(0, 5), Point(1, 1)));

	//Point outside triangle:
	print_result(bsp( Point(0, 0), Point(5, 0), Point(0, 5), Point(4, 4)));
	
	//Point on vertex (outside):
	print_result(bsp( Point(0, 0), Point(5, 0), Point(0, 5), Point(0, 0)));
	
	//Point on edge (outside):
	print_result(bsp( Point(0, 0), Point(5, 0), Point(0, 5), Point(2.5f, 0)));
	
	return (0);
}