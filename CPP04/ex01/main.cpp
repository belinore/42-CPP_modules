/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:48:07 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 18:04:19 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void test_deep_copy();

int main()
{
	std::cout << "[1 - test with base class only]\n";
	Animal base = Animal();
	base.makeSound();
	base.newThought("I have no brain!");
	base.printThoughts();
	std::cout << std::endl;

	//Testing polymorphism with array of Animal pointers -> base class pointer to derived class objects
	std::cout << "\n[2 - polymorphism array of Animal ptrs]\n";
	const Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	// // Adding thoughts to each animal - remove const from Animal array
	// std::cout << "\n[2.0 - adding thoughts to each animal]\n";
	// animals[0]->newThought("I want a bone!");
	// animals[1]->newThought("I want some fish!");
	// animals[2]->newThought("I want to play fetch!");
	// animals[3]->newThought("I want to chase a laser pointer!");

	// Making sounds and printing thoughts for each animal
	std::cout << "\n[2.1 - printing sounds and thoughts for each animal]\n";
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\nAnimal " << i << ":" << std::endl;
		animals[i]->makeSound();
		animals[i]->printThoughts();
	}
	std::cout << std::endl;
	std::cout << "\n[2.3 - clean up]\n";
	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "\n[3 - test for deep copies]\n";
	test_deep_copy();
	return 0;
}

void test_deep_copy()
{
	std::cout << "Constructing Dog with Brain:\n";
	Dog* dog = new Dog();
	std::cout << "\nConstructing Cat with Brain:\n";
	Cat* cat = new Cat();
	std::cout << "\nAdding thoughts to Dog...\n";
	dog->newThought("Throw me the ball!");
	dog->newThought("I want to go for a walk!");
	dog->newThought("I am hungry!");
	std::cout << "Adding thoughts to Cat..." << std::endl;
	cat->newThought("I want to climb the tree!");
	cat->newThought("I want to chase the laser pointer!");
	cat->newThought("I am sleepy!");

	std::cout << "\nCopying Dog to another Dog..." << std::endl;
	Dog *copyDog = new Dog(*dog);

	std::cout << "\nCopying Assigning Cat to another Cat..." << std::endl;
	Cat *copycat = new Cat();
	*copycat = *cat;

	std::cout << "\nAdding new thought to original Dog..." << std::endl;
	dog->newThought("New thought for original dog after copy");

	std::cout << "Adding new thought to original Cat..." << std::endl;
	cat->newThought("New thought for original cat after copy");

	std::cout << "\nDog's thoughts:" << std::endl;
	dog->printThoughts();

	std::cout << "\nCopied Dog's thoughts:" << std::endl;
	copyDog->printThoughts();

	std::cout << "\nCat's thoughts:" << std::endl;
	cat->printThoughts();

	std::cout << "\nCopied Cat's thoughts:" << std::endl;
	copycat->printThoughts();

	std::cout << std::endl;
	std::cout << "Clean up:" << std::endl;
	delete copyDog;
	delete copycat;
	delete dog;
	delete cat;
	return ;
}

// //Without virtual function in base class, it's only possible to access Brain methods by downcasting to Dog* or Cat*
// Dog* dogPtr = dynamic_cast<Dog*>(const_cast<Animal*>(animals[0]));
// dogPtr->newThought("I want a bone!");
// Cat* catPtr = dynamic_cast<Cat*>(const_cast<Animal*>(animals[1]));
// catPtr->newThought("I want some fish!");
// dogPtr->printThoughts();
// catPtr->printThoughts();