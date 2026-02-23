#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, int gradeToSign, int gradetoExecute)
:_name(name)
,_isSigned(false)
,_gradeToSign(gradeToSign)
,_gradeToExecute(gradetoExecute)
{
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
	(void)other;
	//TBC
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

std::ostream &operator<<(std::ostream &oss, Form &form)
{
	oss << "Form " << form.getName()
		<< " (isSigned = " << form.getIsSigned()
		<< ", gradeToSign = " << form.getGradeToSign()
		<< ", gradeToExecute = " << form.getGradeToExecute() << ")";
	return (oss);
}