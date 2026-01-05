#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Constructed: Cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructed: Cat" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Copy Constructed: Cat" << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Copy Assigned: Cat" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}