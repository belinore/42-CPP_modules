#include "Zombie.hpp"

int main(void)
{
    int size = 5;
    Zombie* h = zombieHorde(size, "Zog");
    delete[] h;
}