#ifndef BUREAUCRAT_HPP

#include <iostream>
#include <string>

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
	virtual const char* what() const throw();
};

class GradeTooLowException : public std::exception
{
	public:
	virtual const char* what() const throw();
};

std::ostream &operator<<(std::ostream& os, Bureaucrat& bureaucrat);

#endif