#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define BRAIN_SIZE 100

class Brain
{
	public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);

	void newThought(std::string text);
	void printThoughts();

	private:
	std::string ideas[BRAIN_SIZE];
};

#endif