/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:45:52 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 22:45:53 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	newThought("Hello world!");
	std::cout << "Constructed: Brain" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructed: Brain" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < BRAIN_SIZE; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Copy Constructed: Brain" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < BRAIN_SIZE; i++)
			ideas[i] = other.ideas[i];
	}
	std::cout << "Copy Assigned: Brain" << std::endl;
	return (*this);
}

void Brain::newThought(std::string text)
{
	std::string *thought = new std::string(text);
	int i = 0;
	while (i < BRAIN_SIZE && !ideas[i].empty())
		i++;
	if (i < BRAIN_SIZE - 1)
		ideas[i] = *thought;
	else
		std::cout << "Brain is full of thoughts!" << std::endl;
}

void Brain::printThoughts()
{
	int i = 0;
	while (i < BRAIN_SIZE && !ideas[i].empty()) 
	{
		std::cout << ideas[i] << std::endl;
		i++;
	}
}