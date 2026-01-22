/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:40:44 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 19:40:44 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("Trapster");

	scav.attack("EnemyDroid");
	scav.takeDamage(5);
	scav.guardGate();
	scav.takeDamage(100);
	scav.attack("EnemyDroid");
	scav.beRepaired(3);
}