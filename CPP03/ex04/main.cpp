/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:56:30 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 20:46:53 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("Diamondy");

	diamond.whoAmI();
	diamond.printStatus();
	diamond.attack("EnemyDroid");
	diamond.highFivesGuys();
	diamond.takeDamage(50);
	diamond.attack("EnemyDroid");
}
