/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:00:18 by belinore          #+#    #+#             */
/*   Updated: 2026/02/27 18:00:46 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else
		_grade = grade;
	//std::cout << "Constructed: Bureaucrat " << name << "\n";
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Destructed: Bureaucrat " << _name << "\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	Bureaucrat(other.getName(), other.getGrade());
	//std::cout << "Copy Constructed: Bureaucrat " << _name << "\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other.getGrade();
	}
	return (*this);
	//std::cout << "Copy Assigned: Bureaucrat " << _name << "\n";
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
	return ("Grade is too high [Bureaucrat]");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low [Bureaucrat]");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "\n";
	}
	catch(const std::exception &e)
	{
		std::cerr << "Bureaucrat " << _name
		          << " couldn't sign " << form.getName()
				  << " : " << e.what() << "\n";
	}	
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << "\n";
	}
	catch(const std::exception &e)
	{
		std::cerr << "Bureaucrat " << _name
		          << " couldn't execute " << form.getName()
				  << " : " << e.what() << "\n";
	}
}

