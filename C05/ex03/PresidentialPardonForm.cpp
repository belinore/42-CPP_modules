/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:01:21 by belinore          #+#    #+#             */
/*   Updated: 2026/02/27 18:01:22 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	//std::cout << "Constructed: PresidentialPardonForm\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "Destructed: PresidentialPardonForm\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), _target(other._target)
{
	//std::cout << "Copy Constructed: PresidentialPardonForm\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
	//std::cout << "Copy Assigned: PresidentialPardonForm\n";
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}
