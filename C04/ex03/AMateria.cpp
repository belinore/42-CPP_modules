#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "Constructed: AMateria " << type << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Destructed: AMateria " << _type << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	std::cout << "Copy constructed: AMateria " << _type << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		_type = other._type;
		std::cout << "Copy Assigned: AMateria " << _type << std::endl;
	}
	return (*this);
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses " << _type << " on " << target.getName() << " *" << std::endl;
}