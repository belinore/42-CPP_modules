#include "Zombie.hpp"

int main(void)
{
    Zombie *a = newZombie("New");
    randomChump("Rando");
    Zombie *b = newZombie("Zoom");
    randomChump("Ron");
    Zombie d("Zog");
    std::cout << "ZOMBIES ARE FIGHTING" << std::endl; 
    delete a; // Deallocate memory for the dynamically allocated Zombie
    delete b;
}

