#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("Trapster");

	scav.attack("EnemyDroid");
	scav.takeDamage(5);
	scav.guardGate();
	scav.takeDamage(100);
	scav.attack("EnemyDroid");
	scav.beRepaired(3);
}