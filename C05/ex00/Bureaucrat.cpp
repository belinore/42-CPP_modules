#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name) : _name(name)
{
	std::cout << "Constructed: Bureaucrat " << name << "\n";
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructed: Bureaucrat " << _name << "\n";
}
Bureaucrat::Bureaucrat(Bureaucrat &other)
{
	Bureaucrat(other.getName());
	std::cout << "Copy Constructed: Bureaucrat " << _name << "\n";
}
Bureaucrat &Bureaucrat::operator=(Bureaucrat &other)
{
	(void)other;
	// if (this != &other)
	// {
	// 	this->_name = other.getName();
	// }
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}