/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:40:50 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 19:47:48 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "Constructed: ScavTrap " << name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructed: ScavTrap " << getName() << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Copy Constructed: ScavTrap " << getName() << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "Copy Assigned: ScavTrap " << getName() << std::endl;
	return (*this);
}

void ScavTrap::guardGate()
{
	if (getHitPoints() == 0)
	{
		std::cout << "ScavTrap " << getName() 
		          << " is dead and cannot enter Gate Keeper mode!"
				  << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName() 
	          << " is now in Gate Keeper mode." << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() == 0)
	{
		std::cout << "ScavTrap " << getName()
		          << " is dead and cannot attack!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
	          << getAttackDamage() << " points of damage!" << std::endl;
}