#ifndef BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	public:
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat &other);
	Bureaucrat &operator=(Bureaucrat &other);

	const std::string &getName() const;
	int	getGrade() const;
	void incrementGrade();
	void decrementGrade();

	private:
	const std::string _name;
	int _grade;
};

class GradeTooHighException : public std::exception
{
	public:
	virtual const char* what() const throw()
	{
		return ("Grade is too high");
	}
};

class GradeTooLowException : public std::exception
{
	public:
	virtual const char* what() const throw()
	{
		return ("Grade is too low");
	}
};

#endif