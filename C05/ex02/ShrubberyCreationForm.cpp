/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:00:01 by belinore          #+#    #+#             */
/*   Updated: 2026/02/27 18:00:02 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Constructed: ShrubberyCreationForm\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructed: ShrubberyCreationForm\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), _target(other._target)
{
	std::cout << "Copy Constructed: ShrubberyCreationForm\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::string fileName = _target + "_shrubbery";
	std::ofstream outFile(fileName.c_str());
	if (outFile.is_open())
	{
		outFile << "             _-_              \n";
		outFile << "          /~~   ~~\\          \n";
		outFile << "       /~~    ~   ~~\\        \n";
		outFile << "     /~~   -     -  ~~\\      \n";
		outFile << "    {   -     ~     -  }      \n";
		outFile << "     \\  _-      -_   /       \n";
		outFile << "       ~   \\\\ //  ~         \n";
		outFile << "            | |               \n";
		outFile << "            | |               \n";
		outFile << "           // \\\\            \n";
		outFile.close();
	}
	else
		std::cerr << "Error: Unable to create file: " << fileName << "\n";
}
