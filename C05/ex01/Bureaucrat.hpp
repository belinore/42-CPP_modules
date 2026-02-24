#ifndef BUREAUCRAT_HPP

#include <iostream>
#include <string>

// #define RED     "\033[31m"
// #define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define MAX_GRADE 1
#define MIN_GRADE 150

class Form;

class Bureaucrat
{
	private:
	const std::string _name;
	int _grade;

	public:
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat &other);
	Bureaucrat &operator=(Bureaucrat &other);

	const std::string &getName() const;
	int	getGrade() const;
	void incrementGrade();
	void decrementGrade();

	//ex01
	void signForm(Form &form);
	//endex01

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
