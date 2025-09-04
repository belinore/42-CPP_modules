#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

void Weapon::setType(std::string type)
{
    _type = type;
}

const std::string& Weapon::getType(void)
{
    return (_type);
}

void HumanA::attack(void)
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

void HumanB::attack(void)
{
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " does not have a weapon" << std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}

int main(void)
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
}