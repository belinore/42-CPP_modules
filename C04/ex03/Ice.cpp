#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Constructed: Ice" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Destructed: Ice" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Copy Constructed: Ice" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	std::cout << "Copy Assigned: Ice" << std::endl;
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}