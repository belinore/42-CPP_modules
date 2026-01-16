/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:53:23 by belinore          #+#    #+#             */
/*   Updated: 2026/01/16 16:53:29 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    public:
    Zombie(std::string name);
    ~Zombie();
	
    void    announce(void);

    private:
    std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif