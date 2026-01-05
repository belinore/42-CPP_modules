#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Constructed: Dog" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructed: Dog" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Copy Constructed: Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Copy Assigned: Dog" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}
