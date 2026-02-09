/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:41:57 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 13:16:41 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
	Animal();
	Animal(const std::string &type);
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	virtual void makeSound() const = 0; //pure virtual function
	virtual void newThought(std::string text) = 0;
	virtual void printThoughts() const = 0;
	std::string getType() const;

	protected:
	std::string _type;
};

#endif

//by making makeSound a pure virtual function, Animal becomes abstract 
//meaning that it cannot be instantiated directly and child classes must implement 
//makeSound to be instantiable