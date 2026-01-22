/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:56:11 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 19:56:11 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
	: _name(name)
	, _hitPoints(10)
	, _energyPoints(10)
	, _attackDamage(0)
{
	std::cout << "Constructed: ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, int hitPoints,
                   int energyPoints, int attackDamage)
	: _name(name)
	, _hitPoints(hitPoints)
	, _energyPoints(energyPoints)
	, _attackDamage(attackDamage)
{
	std::cout << "Constructed: ClapTrap " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructed: ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name)
	, _hitPoints(other._hitPoints)
	, _energyPoints(other._energyPoints)
	, _attackDamage(other._attackDamage)
{
	std::cout << "Copy Constructed: ClapTrap " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "Copy Assigned: ClapTrap " << _name << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name
		          << " is dead and cannot attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
	          << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints < amount)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount
		          << " points of damage and dies!" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount
	          << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name
		          << " is dead and cannot be repaired!" << std::endl;
		return ;
	}
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name
	          << " is repaired with " << amount << " points!" << std::endl;
}
std::string ClapTrap::getName() const
{
	return (_name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

void ClapTrap::printStatus() const
{
	std::cout << "ClapTrap " << _name << " Status - Hit Points: " << _hitPoints
			  << ", Energy Points: " << _energyPoints
			  << ", Attack Damage: " << _attackDamage << std::endl;
}