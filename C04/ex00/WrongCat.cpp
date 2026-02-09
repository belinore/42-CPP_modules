/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:50:45 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 14:29:59 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
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
	std::cout << "Meow Meow!" << std::endl;
}