#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i)
    {
        horde[i].set_name(name); // Assuming setName is a method in the Zombie class
        horde[i].announce();
    }
    return (horde);
}