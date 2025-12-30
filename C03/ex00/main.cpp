#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1("Clappytron");
	ClapTrap clap2("Trapster");

	clap1.attack("TargetBot");
	clap1.takeDamage(7);
	clap1.beRepaired(4);
	clap2.attack("EnemyDroid");
	clap2.takeDamage(5);
	clap2.takeDamage(6);
	clap2.attack("EnemyDroid");
	clap2.beRepaired(3);
	clap1.beRepaired(4);
}