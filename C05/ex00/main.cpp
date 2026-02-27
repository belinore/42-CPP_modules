/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:53:51 by belinore          #+#    #+#             */
/*   Updated: 2026/02/27 17:53:53 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat *createBureaucrat(std::string name, int grade)
{
	Bureaucrat *p = NULL;
	try
	{
		p = new Bureaucrat(name, grade);
	}
	catch (const std::exception &e)
	{
		std::cout << "Bureaucrat " << name << " was not created : " << e.what() << "\n";
		return (p);
	}
	std::cout << *p << "\n";
	return (p);
}

void testGrade(std::string name, int grade)
{
	try
	{
		Bureaucrat a(name, grade);
	}
	catch (const std::exception &e)
	{
		std::cout << "Bureaucrat " << name << " was not created : " << e.what() << "\n";
		return ;
	}
	std::cout << "Bureaucrat construction is valid for " << name << " with grade " << grade << "\n";
	return ;
}

int main()
{
	std::string cyan = "\033[36m";
	std::string reset = "\033[0m";

	std::cout << cyan << "VALID BUREAUCRAT CONSTRUCTIONS (stack)\n" << reset;
	testGrade("Employee1", 1);//valid
	testGrade("Employee2", 150);//valid
	testGrade("Employee3", 50);//valid
	std::cout << cyan << "VALID BUREAUCRAT CONSTRUCTIONS (heap)\n" << reset;
	Bureaucrat *a = createBureaucrat("Alice", 15);
	Bureaucrat *b = createBureaucrat("Beth", 1);

	std::cout << cyan << "INVALID BUREAUCRAT CONSTRUCTIONS\n" << reset;
	Bureaucrat *c = createBureaucrat("Chris", 155);
	testGrade("Employee4", 0);//too high
	testGrade("Employee5", -1);//too high
	testGrade("Employee6", 151);//too low
	testGrade("Employee7", 100000000);//too low

	std::cout << cyan << "CLEAN UP\n" << reset;
	delete a;
	delete b;
	delete c;
}