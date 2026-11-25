/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:17:42 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 13:17:43 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	public:
	Cure();
	~Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif