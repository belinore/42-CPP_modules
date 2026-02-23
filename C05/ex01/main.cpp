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

int main()
{
	Bureaucrat *b = createBureaucrat("Beth", 1);
	Form a("Application", 2, 1);
	std::cout << a << "\n";
	
	a.beSigned(*b);
	std::cout << a << "\n";

}
