/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:18:07 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 13:18:08 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class AMateria;

// MateriaSource class implements the IMateriaSource interface to manage and create AMateria objects.
class MateriaSource : public IMateriaSource
{
	public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const &type);

	private:
	AMateria* _inventory[4];
	int _count;
};

#endif
