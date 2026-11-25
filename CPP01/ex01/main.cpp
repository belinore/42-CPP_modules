/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:58:20 by belinore          #+#    #+#             */
/*   Updated: 2026/01/19 14:45:17 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int size = 5;
	
	std::cout << "Creating zombie horde..." << std::endl;
    Zombie* h = zombieHorde(size, "Zog");
	
	std::cout << "\nCalling annouce for every zombie in horde:" << std::endl;
	for (int i = 0; i < size; i++)
        h[i].announce();
		
	std::cout << "\nCleaning up memory:" << std::endl;
    delete[] h;
}