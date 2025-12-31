#include <ostream>
#include "Animal.hpp"

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
		_type = other._type; //q: is writing this->type equalivant to _type alone?
	}
	std::cout << "Copy Assigned: Animal " << _type << std::endl;	
}