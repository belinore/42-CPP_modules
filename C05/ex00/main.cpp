#include "Bureaucrat.hpp"

void testGradeTooHigh()
{
	try
	{
		Bureaucrat a("Alice", 0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
		return ;
	}
	//std::cout << a.getName() << " has grade " << a.getGrade() << "\n";
}

void testGradeTooLow()
{
	try
	{
		Bureaucrat a("Bob", 151);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}

int main()
{
	Bureaucrat a("Beth", 1);
	std::cout << a.getName() << " has grade " << a.getGrade() << "\n";
	testGradeTooHigh();
	testGradeTooLow();

}