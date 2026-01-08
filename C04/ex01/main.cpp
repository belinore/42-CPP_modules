# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

// int main()
// {
// 	std::cout << "Constructing Dog with Brain:" << std::endl;
// 	Dog* dog = new Dog();
// 	dog->makeSound();
// 	//const Animal* j = new Dog();
// 	//Dog* dogPtr = dynamic_cast<Dog*>(const_cast<Animal*>(j));
// 	std::cout << "\nConstructing Cat with Brain:" << std::endl;
// 	Cat* cat = new Cat();
// 	cat->makeSound();

// 	std::cout << "\nAdding thoughts to Dog..." << std::endl;
// 	dog->newThought("Throw me the ball!");
// 	dog->newThought("I want to go for a walk!");
// 	dog->newThought("I am hungry!");
// 	dog->newThought("I want to play fetch!");
// 	dog->newThought("I love my human!");
// 	dog->newThought("I want a belly rub!");
// 	dog->newThought("I want to dig a hole!");

// 	std::cout << "\nAdding thoughts to Cat..." << std::endl;
// 	cat->newThought("I want to climb the tree!");
// 	cat->newThought("I want to chase the laser pointer!");
// 	cat->newThought("I am sleepy!");
// 	cat->newThought("I want to knock things off the table!");
// 	cat->newThought("I want to catch a mouse!");

// 	std::cout << "\nCopying Dog to another Dog..." << std::endl;
// 	Dog *copyDog = new Dog(*dog);

// 	std::cout << "\nCopying Cat to another Cat..." << std::endl;
// 	Cat *copycat = new Cat();
// 	*copycat = *cat;

// 	std::cout << "\nAdding new thought to original Dog..." << std::endl;
// 	dog->newThought("New thought for original dog after copy");

// 	std::cout << "\nAdding new thought to original Cat..." << std::endl;
// 	cat->newThought("New thought for original cat after copy");

// 	std::cout << "\nDog's thoughts:" << std::endl;
// 	dog->printThoughts();

// 	std::cout << "\nCopied Dog's thoughts:" << std::endl;
// 	copyDog->printThoughts();

// 	std::cout << "\nCat's thoughts:" << std::endl;
// 	cat->printThoughts();

// 	std::cout << "\nCopied Cat's thoughts:" << std::endl;
// 	copycat->printThoughts();

// 	std::cout << std::endl;
// 	delete copyDog;
// 	delete copycat;
// 	delete dog;
// 	delete cat;
// 	return 0;
// }

int main()
{
	//Testing base Animal class
	Animal meta = Animal();
	meta.makeSound();
	meta.newThought("I have no brain!");
	meta.printThoughts();
	std::cout << std::endl;

	//Testing polymorphism with array of Animal pointers -> base class pointer to derived class objects
	const Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	// // Adding thoughts to each animal - remove const from Animal array
	// animals[0]->newThought("I want a bone!");
	// animals[1]->newThought("I want some fish!");
	// animals[2]->newThought("I want to play fetch!");
	// animals[3]->newThought("I want to chase a laser pointer!");

	// Making sounds and printing thoughts for each animal
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\nAnimal " << i << ":" << std::endl;
		animals[i]->makeSound();
		animals[i]->printThoughts();
	}
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}

	// //Without virtual function in base class, it's only possible to access Brain methods by downcasting to Dog* or Cat*
	// Dog* dogPtr = dynamic_cast<Dog*>(const_cast<Animal*>(animals[0]));
	// dogPtr->newThought("I want a bone!");
	// Cat* catPtr = dynamic_cast<Cat*>(const_cast<Animal*>(animals[1]));
	// catPtr->newThought("I want some fish!");
	// dogPtr->printThoughts();
	// catPtr->printThoughts();