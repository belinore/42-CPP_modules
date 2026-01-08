# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include <string>
# include <iostream>

int main()
{
	// //Testing base Animal class - won't work as Animal is now abstract
	// Animal meta = Animal();
	// meta.makeSound();
	// meta.newThought("I have no brain!");
	// meta.printThoughts();
	// std::cout << std::endl;

	int totalAnimals = 10;
	const Animal* animals[totalAnimals];
	int i = 0;
	while (i < totalAnimals)
	{
		animals[i++] = new Dog();
		if (i < totalAnimals)
			animals[i++] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		animals[i]->makeSound();
		std::string thought = "I am " + animals[i]->getType() + " number " + std::to_string(i);
		//animals[i]->newThought(thought);
		animals[i]->printThoughts();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	return 0;
}