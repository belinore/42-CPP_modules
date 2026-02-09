#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Constructed: Cure" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Destructed: Cure" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Copy Constructed: Cure" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	std::cout << "Copy Assigned: Cure" << std::endl;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}