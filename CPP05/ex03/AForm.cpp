/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:00:08 by belinore          #+#    #+#             */
/*   Updated: 2026/02/27 18:00:09 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
:_name(name)
,_isSigned(false)
,_gradeToSign(gradeToSign)
,_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw GradeTooHighException();
	else if (gradeToSign > MIN_GRADE|| gradeToExecute > MIN_GRADE)
		throw GradeTooLowException();
	//std::cout << "Constructed: AForm " << name << "\n";
}

AForm::~AForm()
{
	//std::cout << "Destructed: AForm " << _name << "\n";
}

AForm::AForm(const AForm &other)
:_name(other.getName())
,_isSigned(false)
,_gradeToSign(other.getGradeToSign())
,_gradeToExecute(other.getGradeToExecute())
{
	//std::cout << "Copy Constructed: AForm " << _name << "\n";
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other.getIsSigned();
	}
	return (*this);
	//std::cout << "Copy Assigned: AForm " << _name << "\n";
}

const std::string &AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high [AForm]");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low [AForm]");
}

std::ostream &operator<<(std::ostream &oss, AForm &form)
{
	oss << "AForm " << form.getName()
		<< " (isSigned = " << form.getIsSigned()
		<< ", gradeToSign = " << form.getGradeToSign()
		<< ", gradeToExecute = " << form.getGradeToExecute() << ")";
	return (oss);
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}
