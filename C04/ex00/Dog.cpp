/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:50:17 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 14:30:21 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Constructed: Dog" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructed: Dog" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Copy Constructed: Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Copy Assigned: Dog" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}
