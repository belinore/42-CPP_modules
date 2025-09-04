#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    public:
    Weapon(void) : _type("") {}
    Weapon(std::string type) : _type(type) {}
    //~Weapon();
    const std::string& getType();
    void setType(std::string type);

    private:
    std::string _type;
};

#endif