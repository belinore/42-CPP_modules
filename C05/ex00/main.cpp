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
		std::cout << e.what() << " : " << name << " with grade " << grade << "\n";
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
		std::cout << e.what() << " : " << name << " with grade " << grade << "\n";
		return ;
	}
	std::cout << "Valid Bureaucrat construction for " << name << " with grade " << grade << "\n";
	return ;
}

int main()
{
	testGrade("Employee1", 1);//valid
	testGrade("Employee2", 150);//valid
	testGrade("Employee3", 50);//valid

	testGrade("Employee4", 0);//too high
	testGrade("Employee5", -1);//too high

	testGrade("Employee6", 151);//too low
	testGrade("Employee7", 100000000);//too low

	Bureaucrat *a = createBureaucrat("Alice", 15);
	Bureaucrat *b = createBureaucrat("Beth", 1);
	Bureaucrat *c = createBureaucrat("Chris", 155);

	delete a;
	delete b;
	delete c;

}