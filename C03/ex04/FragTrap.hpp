/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:56:26 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 20:29:18 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
	FragTrap(const std::string &name);
	~FragTrap();
	FragTrap(const FragTrap &other);

	FragTrap &operator=(const FragTrap &other);

	void highFivesGuys(void);
};

#endif