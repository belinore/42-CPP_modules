/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:47:03 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 22:47:03 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Constructed: WrongCat" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructed: WrongCat" << std::endl;
}
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "Copy Constructed: WrongCat" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << "Copy Assigned: WrongCat" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WRONG Meow Meow!" << std::endl;
}