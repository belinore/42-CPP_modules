/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:41:48 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 17:50:53 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <string>
#include <iostream>
#include <sstream>

std::string intToString(int n)
{
    std::ostringstream oss;
    oss << n;
    return oss.str();
}

int main()
{
	// //Testing base Animal class - it won't compile since Animal is now abstract
	// Animal base = Animal();
	// base.makeSound();
	// base.newThought("I have no brain!");
	// base.printThoughts();

	//General brain testing similar to ex01
	const int totalAnimals = 10;
	Animal* animals[totalAnimals];
	int i = 0;
	while (i < totalAnimals)
	{
		animals[i++] = new Dog();
		if (i < totalAnimals)
			animals[i++] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		animals[i]->makeSound();
		std::string thought = "I am " + animals[i]->getType()
			+ " number " + intToString(i);
		animals[i]->newThought(thought);
		animals[i]->printThoughts();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	return (0);
}