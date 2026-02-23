#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << "Constructed: Bureaucrat " << name << "\n";
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructed: Bureaucrat " << _name << "\n";
}
Bureaucrat::Bureaucrat(Bureaucrat &other)
{
	Bureaucrat(other.getName(), other.getGrade());
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

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	_grade++;
}

const char* GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

