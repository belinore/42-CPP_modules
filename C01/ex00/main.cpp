/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:49:12 by belinore          #+#    #+#             */
/*   Updated: 2026/01/16 16:49:13 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *a = newZombie("New");
    randomChump("Rando");
    Zombie *b = newZombie("Zoom");
    randomChump("Ron");
    Zombie d("Zog");
    std::cout << "ZOMBIES ARE FIGHTING" << std::endl; 
    delete a;
    delete b;
}

