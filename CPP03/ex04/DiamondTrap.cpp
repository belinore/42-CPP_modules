/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:55:51 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 20:55:52 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name", 100, 50, 30)
	, FragTrap(name)
	, ScavTrap(name)
	, _name(name)
{
	std::cout << "Constructed: DiamondTrap " << _name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructed: DiamondTrap " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other)
	, FragTrap(other)
	, ScavTrap(other)
	, _name(other._name)
{
	std::cout << "Copy Constructed: DiamondTrap " << _name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	std::cout << "Copy Assigned: DiamondTrap " << _name << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name
	          << ", ClapTrap name: " << ClapTrap::getName() << std::endl;
}
