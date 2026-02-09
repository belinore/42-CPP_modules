/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:50:09 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 16:59:20 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Constructed: Cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructed: Cat" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Copy Constructed: Cat" << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Copy Assigned: Cat" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}
