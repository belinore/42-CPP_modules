/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:50:38 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 14:33:30 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "Constructed: WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructed: WrongAnimal" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << "Copy Constructed: WrongAnimal " << _type << std::endl;	
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	std::cout << "Copy Assigned: WrongAnimal " << _type << std::endl;
	return (*this);	
}

void WrongAnimal::makeSound() const
{
	std::cout << "*Unidentifiable animal sound*" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}