#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap frag("Trapster");

	frag.attack("EnemyDroid");
	frag.printStatus();
	frag.highFivesGuys();
	frag.takeDamage(100);
	frag.printStatus();
	frag.attack("EnemyDroid");
	frag.beRepaired(3);
}