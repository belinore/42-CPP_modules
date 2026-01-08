#include <ostream>
#include "Animal.hpp"

Animal::Animal() : Animal("Animal") {}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "Constructed: Animal" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Destructed: Animal" << std::endl;
}
Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "Copy Constructed: Animal " << _type << std::endl;	
}
Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	std::cout << "Copy Assigned: Animal " << _type << std::endl;
	return (*this);	
}

void Animal::makeSound() const
{
	std::cout << "Animal sound!" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}

void Animal::newThought(std::string text)
{
	(void)text;
	std::cout << "Animal has no brain to think!" << std::endl;
}

void Animal::printThoughts() const
{
	std::cout << "Animal has no brain to show thoughts!" << std::endl;
}