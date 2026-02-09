/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:50:05 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 14:32:43 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	virtual void makeSound() const;
	std::string getType() const;

	protected:
	std::string _type;
};

#endif