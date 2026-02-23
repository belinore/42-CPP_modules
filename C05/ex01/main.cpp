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

void signForm(Bureaucrat &bureaucrat, Form &form)
{
	try
	{
		form.beSigned(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	Bureaucrat *b = createBureaucrat("Beth", 50);
	Form a("Application", 2, 1);
	std::cout << a << "\n";
	
	signForm(*b, a);
	std::cout << a << "\n";

}
