#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "Constructed: FragTrap " << name << std::endl;
}
FragTrap::~FragTrap()
{
	std::cout << "Destructed: FragTrap " << getName() << std::endl;
}
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copy Constructed: FragTrap " << getName() << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)//q: is "this" a pointer address //a:
	{
		ClapTrap::operator=(other);
	}
	std::cout << "Copy Assigned: Fragtrap " << getName() << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (getHitPoints() < 0)
	{
		std::cout << "Fragtrap " << getName() << " is dead and cannot request a high five!" << std::endl;
		return ;
	}
	std::cout << "Fragtrap " << getName() << " requests a high five!" << std::endl;
}