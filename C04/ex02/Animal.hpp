#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

//abstract base class
class Animal
{
	public:
	Animal();
	Animal(const std::string &type);
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	virtual void makeSound() const = 0; //pure virtual function
	virtual void newThought(std::string text) = 0;
	virtual void printThoughts() const = 0;
	std::string getType() const;

	protected:
	std::string _type;
};

#endif