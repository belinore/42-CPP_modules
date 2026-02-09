#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class ICharacter;

// The Ice class represents a specific type of magical materia that can be used to perform ice-related actions.
class Ice : public AMateria
{
	public:
	Ice();
	~Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif