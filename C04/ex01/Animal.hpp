/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:14:16 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 13:14:18 by belinore         ###   ########.fr       */
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

	virtual void makeSound() const;
	virtual void newThought(std::string text);
	virtual void printThoughts() const;
	std::string getType() const;

	protected:
	std::string _type;
};

#endif