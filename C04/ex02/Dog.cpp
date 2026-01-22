/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:46:28 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 22:46:29 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog")
{
	_brain = new Brain();
	_brain->newThought("I am a new dog brain!");
	std::cout << "Constructed: Dog" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Destructed: Dog" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Copy Constructed: Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	std::cout << "Copy Assigned: Dog" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

void Dog::newThought(std::string text)
{
	_brain->newThought(text);
}

void Dog::printThoughts() const
{
	_brain->printThoughts();
}
