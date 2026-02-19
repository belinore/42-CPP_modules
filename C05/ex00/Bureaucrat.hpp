#ifndef BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	public:
	Bureaucrat(const std::string &name);
	~Bureaucrat();
	Bureaucrat(Bureaucrat &other);
	Bureaucrat &operator=(Bureaucrat &other);

	const std::string &getName() const;

	private:
	const std::string _name;
};

#endif