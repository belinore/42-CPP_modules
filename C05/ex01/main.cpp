#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat *createBureaucrat(std::string name, int grade)
{
	Bureaucrat *p = NULL;
	try
	{
		p = new Bureaucrat(name, grade);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << " : " << name << " with grade " << grade << "\n";
		return (p);
	}
	std::cout << *p << "\n";
	return (p);
}

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
	std::cout << "\n";
	return ;
}

int main()
{
	std::cout << CYAN << "INVALID BUREAUCRAT CONSTRUCTIONS\n" << RESET;
	test("Sam", 500, "Application1", 2, 1);
	test("Tim", 0, "Application2", 2, 1);

	std::cout << CYAN << "INVALID FORM CONSTRUCTIONS\n" << RESET;
	test("Bob", 1, "Application3", 200, 1);
	test("Joe", 1, "Application4", 0, 1);

	std::cout << CYAN << "VALID AND ABLE TO SIGN\n" << RESET;
	test("Cat", 1, "Application5", 2, 1);
	test("Beth", 50, "Application6", 150, 100);
	
	std::cout << CYAN << "VALID BUT UNABLE TO SIGN\n" << RESET;
	test("Jane", 140, "Application7", 139, 1);
	test("Ella", 50, "Application8", 5, 2);

}

	// Bureaucrat *b = createBureaucrat("Beth", 50);
	// Form a("Application", 2, 1);
	// std::cout << a << "\n";
	
	// b->signForm(a);
	// std::cout << a << "\n";