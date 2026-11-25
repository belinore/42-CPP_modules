/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:01:11 by belinore          #+#    #+#             */
/*   Updated: 2026/02/27 18:01:12 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

class AForm;

class Intern
{
	public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	
	AForm *makeForm(std::string name, std::string target);
	AForm *makeShrubberyCreationForm(std::string target);
	AForm *makeRobotomyRequestForm(std::string target);
	AForm *makePresidentialPardonForm(std::string target);
};

#endif