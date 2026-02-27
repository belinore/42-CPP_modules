/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:54:38 by belinore          #+#    #+#             */
/*   Updated: 2026/02/27 17:54:39 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void test(std::string b_name, int b_grade, std::string f_name, int f_grade_sign, int f_grade_execute)
{
	try
	{
		Bureaucrat a(b_name, b_grade);
		Form f(f_name, f_grade_sign, f_grade_execute);
		a.signForm(f);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Bureaucrat " << b_name << " was not created : " << e.what() << "\n";
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << b_name << " was not created : " << e.what() << "\n";
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << "Form " << f_name << " was not created : " << e.what() << "\n";
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << "Form " << f_name << " was not created : " << e.what() << "\n";	
	}
	return ;
}

int main()
{
	std::string cyan = "\033[36m";
	std::string reset = "\033[0m";

	std::cout << cyan << "INVALID BUREAUCRAT CONSTRUCTIONS\n" << reset;
	test("Sam", 500, "Application1", 2, 1);
	test("Tim", 0, "Application2", 2, 1);

	std::cout << cyan << "INVALID FORM CONSTRUCTIONS\n" << reset;
	test("Bob", 1, "Application3", 200, 1);
	test("Joe", 1, "Application4", 0, 1);

	std::cout << cyan << "VALID AND ABLE TO SIGN\n" << reset;
	test("Cat", 1, "Application5", 2, 1);
	test("Beth", 50, "Application6", 150, 100);
	
	std::cout << cyan << "VALID BUT UNABLE TO SIGN\n" << reset;
	test("Jane", 140, "Application7", 139, 1);
	test("Ella", 50, "Application8", 5, 2);

}
