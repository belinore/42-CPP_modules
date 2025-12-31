#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
	Animal(const std::string &type);
	~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	protected:
	std::string _type;
};

#endif