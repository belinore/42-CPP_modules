/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:47:51 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 22:47:51 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal("Cat")
{
	_brain = new Brain();
	_brain->newThought("I am a new cat brain!");
	std::cout << "Constructed: Cat" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Destructed: Cat" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Copy Constructed: Cat" << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	std::cout << "Copy Assigned: Cat" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}

void Cat::newThought(std::string text)
{
	_brain->newThought(text);
}

void Cat::printThoughts() const
{
	_brain->printThoughts();
}