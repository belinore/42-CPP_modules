#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

const std::string& Weapon::getType(void)
{
    return (_type);
}

int main(void)
{
    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
		// Weapon sword = Weapon("sword");
		// bob.setWeapon(sword);
		// bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");

        HumanB jim("Jim");
        // jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
}