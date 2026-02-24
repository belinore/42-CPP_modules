#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
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
	if (this != &other)
	{
		this->_grade = other.getGrade();
	}
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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "\n";
	}
	catch(const std::exception &e)
	{
		std::cout << "Bureaucrat " << _name
		          << " couldn't sign " << form.getName()
				  << " : " << e.what() << "\n";
	}	
}
