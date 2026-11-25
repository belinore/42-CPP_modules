/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:01:07 by belinore          #+#    #+#             */
/*   Updated: 2026/02/27 18:01:07 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "Constructed: Intern\n";
}

Intern::~Intern()
{
	std::cout << "Destructed: Intern\n";
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Copy Constructed: Intern\n";
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
	std::cout << "Copy Assigned: Intern\n";
}

//ReturnType (ClassName::*PointerName)(ParameterTypes);
AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*formMakers[3])(std::string) = {&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << " form\n";
			return ((this->*formMakers[i])(target));
		}
	}
	std::cout << "Form name \"" << name << "\" is invalid\n";
	return (NULL);
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

//Alternative approach
// AForm *Intern::makeForm(std::string name, std::string target)
// {
// 	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
// 	int i = 0;
// 	while (i < 3)
// 	{
// 		if (name == formNames[i])
// 			break ;
// 		i++;
// 	}
// 	if (i == 3)
// 	{
// 		std::cout << "Form name " << name << " is invalid\n";
// 		return (NULL);
// 	}
// 	std::cout << "Intern creates " << name << " form\n";
// 	switch (i)
// 	{
// 		case 0: return (new ShrubberyCreationForm(target));
// 		case 1: return (new RobotomyRequestForm(target));
// 		case 2: return (new PresidentialPardonForm(target));
// 	}
// 	return (NULL);
// }
