/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:56:30 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 19:56:31 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap frag("Trapster");

	frag.attack("EnemyDroid");
	frag.printStatus();
	frag.highFivesGuys();
	frag.takeDamage(100);
	frag.printStatus();
	frag.attack("EnemyDroid");
	frag.beRepaired(3);
}