#include "Weapon.hpp"

Weapon::Weapon(void) : _type("") {}

Weapon::Weapon(std::string type) : _type(type) {}

void Weapon::setType(std::string type)
{
    _type = type;
}
