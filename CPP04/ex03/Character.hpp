/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:17:36 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 13:17:37 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "Character.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	protected:
	std::string _name;
	AMateria* _inventory[4];

	public:
	Character();
	Character(const std::string &name);
	~Character();
	Character(const Character &other);
	Character &operator=(const Character &other);

	std::string const &getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif