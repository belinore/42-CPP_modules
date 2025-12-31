#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Constructed: Cat" << std::endl;
}
Cat::~Cat()
{

}
Cat::Cat(const Cat &other)
{

}
Cat &Cat::operator=(const Cat &other)
{
	
}