/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:55:36 by belinore          #+#    #+#             */
/*   Updated: 2026/02/28 10:35:49 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat
{
	private:
	const std::string _name;
	int _grade;

	public:
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string &getName() const;
	int	getGrade() const;
	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &form);
	void executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw();
		
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

};

std::ostream &operator<<(std::ostream& os, Bureaucrat& bureaucrat);

#endif
