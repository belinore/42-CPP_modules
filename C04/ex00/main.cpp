/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:50:24 by belinore          #+#    #+#             */
/*   Updated: 2026/01/22 22:50:24 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main()
{
	std::cout << "[1 - Generic]\n";
	Animal animal = Animal("Generic");
	animal.makeSound();
	std::cout << std::endl;

	std::cout << "[2 - Dog]\n";
	Dog dog = Dog();
	dog.makeSound();
	std::cout << std::endl;

	std::cout << "[3 - Cat]\n";
	Cat cat = Cat();
	cat.makeSound();
	std::cout << std::endl;

	std::string str = "Bird";
	if (str == "Cat")
	{
		std::cout << "[4 - Copy Cat]\n";
		Cat copyCat = Cat(cat);
		copyCat = cat;
		std::cout << std::endl;
	}
	else if (str == "Dog")
	{
		std::cout << "[4 - Copy Dog]\n";
		Dog copyDog = Dog(dog);
		copyDog = dog;
		std::cout << std::endl;
	}
	else 
	{
		std::cout << "[4 - Copy Animal]\n";
		Animal copyAnimal = Animal(animal);
		copyAnimal = animal;
		std::cout << std::endl;
	}
}

// int main()
// {
// 	//Test from subject
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	delete meta;
// 	delete j;
// 	delete i;

// 	//WrongAnimal test
// 	const WrongAnimal* wrongMeta = new WrongAnimal();
// 	const WrongAnimal* wrongCat = new WrongCat();
// 	std::cout << wrongCat->getType() << " " << std::endl;
// 	wrongCat->makeSound(); //will output the wrong animal sound!
// 	wrongMeta->makeSound();
// 	delete wrongMeta;
// 	delete wrongCat;

// 	//Mixed tests - should not compile
// 	// const Animal* a = new WrongCat();
// 	// const WrongAnimal* wa = new Cat();
// 	return 0;
// }