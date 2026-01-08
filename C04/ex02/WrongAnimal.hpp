#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
	WrongAnimal();
	WrongAnimal(const std::string &type);
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);

	virtual void makeSound() const; //removed virtual
	std::string getType() const;

	protected:
	std::string _type;
};

#endif