#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

	public:
	Form(const std::string name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(Form &other);
	Form &operator=(Form &other);

	const std::string &getName();
	bool getIsSigned();
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &oss, Form &form);

#endif