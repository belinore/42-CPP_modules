#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
:_name(name)
,_isSigned(false)
,_gradeToSign(gradeToSign)
,_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw GradeTooHighException();
	else if (gradeToSign > MIN_GRADE|| gradeToExecute > MIN_GRADE)
		throw GradeTooLowException();
	std::cout << "Constructed: Form" << "\n";
}

Form::~Form()
{
	std::cout << "Destructed: Form" << "\n";
}

Form::Form(Form &other)
:_name(other.getName())
,_isSigned(false)
,_gradeToSign(other.getGradeToSign())
,_gradeToExecute(other.getGradeToExecute())
{
	std::cout << "Copy Constructed: Form" << "\n";
}

Form &Form::operator=(Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other.getIsSigned();
	}
	return (other);
}

const std::string &Form::getName()
{
	return (_name);
}

bool Form::getIsSigned()
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &oss, Form &form)
{
	oss << "Form " << form.getName()
		<< " (isSigned = " << form.getIsSigned()
		<< ", gradeToSign = " << form.getGradeToSign()
		<< ", gradeToExecute = " << form.getGradeToExecute() << ")";
	return (oss);
}