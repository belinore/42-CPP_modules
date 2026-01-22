/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:40:10 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 19:40:11 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1("Clappytron");
	ClapTrap clap2("Trapster");

	clap1.attack("TargetBot");
	clap1.takeDamage(7);
	clap1.beRepaired(4);
	clap2.attack("EnemyDroid");
	clap2.takeDamage(5);
	clap2.takeDamage(6);
	clap2.attack("EnemyDroid");
	clap2.beRepaired(3);
	clap1.beRepaired(4);
}