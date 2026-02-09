/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:17:33 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 13:17:34 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
	std::cout << "Constructed: Character " << _name << std::endl;
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
	std::cout << "Constructed: Character " << _name << std::endl;

}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "Destructed: Character " << _name << std::endl;
}

Character::Character(const Character &other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
	std::cout << "Copy Constructed: Character " << _name << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	std::cout << "Copy Assigned: Character " << _name << std::endl;
	return (*this);
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " to slot " << i << " of " << _name << std::endl;
			return;
		}
	}
	std::cout << _name << "'s inventory is full! Cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid inventory index!" << std::endl;
		return;
	}
	if (_inventory[idx])
	{
		std::cout << "Unequipped " << _inventory[idx]->getType() << " from slot " << idx << " of " << _name << std::endl;
		_inventory[idx] = nullptr;
	}
	else
	{
		std::cout << "No materia to unequip in slot " << idx << " of " << _name << std::endl;
	}
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid inventory index!" << std::endl;
		return;
	}
	if (_inventory[idx])
	{
		_inventory[idx]->use(target);
	}
	else
	{
		std::cout << "No materia in slot " << idx << " of " << _name << std::endl;
	}
}