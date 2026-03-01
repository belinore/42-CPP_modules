/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:01:29 by belinore          #+#    #+#             */
/*   Updated: 2026/03/01 10:21:49 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	//std::cout << "Constructed: RobotomyRequestForm\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "Destructed: RobotomyRequestForm\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), _target(other._target)
{
	//std::cout << "Copy Constructed: RobotomyRequestForm\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << "Bzzzz... Bzzzz... *drilling noises*... ";
	srand(time(NULL));
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully!\n";
	else
		std::cout << "Failed to robotomize " << _target << ".\n";
}
