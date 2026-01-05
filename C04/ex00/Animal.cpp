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