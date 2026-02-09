/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:50:24 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 16:52:19 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "[1 - Generic]\n";
	Animal animal = Animal();
	std::cout << "Type: " << animal.getType() << "\n";
	animal.makeSound();

	std::cout << "\n[2 - Dog]\n";
	Dog dog = Dog();
	std::cout << "Type: " << dog.getType() << "\n";
	dog.makeSound();

	std::cout << "\n[3 - Cat]\n";
	Cat cat = Cat();
	std::cout << "Type: " << cat.getType() << "\n";
	cat.makeSound();

	std::cout << "\n[4 - Copy Construct Cat]\n";
	Cat copyCat = Cat(cat);
	std::cout << "Type: " << copyCat.getType() << "\n";
	copyCat.makeSound();

	std::cout << "\n[5 - Copy Assign Cat]\n";
	copyCat = cat;
	std::cout << "Type: " << copyCat.getType() << "\n";
	copyCat.makeSound();

	std::cout << "\n[5 - Copy Dog]\n";
	Dog copyDog = Dog(dog);
	std::cout << "Type: " << copyDog.getType() << "\n";
	copyDog.makeSound();

	std::cout << "\n[6 - Copy Assign Dog]\n";
	copyDog = dog;
	std::cout << "Type: " << copyDog.getType() << "\n";
	copyDog.makeSound();

	std::cout << "\n[7 - Animal ptr with Cat]\n";
	const Animal* animal_ptr = new Cat();
	std::cout << "Type: " << animal_ptr->getType() << "\n";
	animal_ptr->makeSound();
	delete animal_ptr;

	std::cout << "\n[8 - WrongCat test -> outputs the WrongAnimal sound]\n";
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "wrongCat Type: " << wrongCat->getType() << "\n";
	std::cout << "wrongCat Sound: ";
	wrongCat->makeSound();
	delete wrongCat;
	
	//INCORRECT tests - creates a generic animal
	std::cout << "\n[9 - no Cat object is created - no polymorphism]\n";
	Animal a = Cat();//object slicing
	std::cout << "Type: " << a.getType() << "\n";
	a.makeSound();
	Animal* p = new Animal("Cat");
	std::cout << "Type: " << p->getType() << "\n";
	p->makeSound();
	std::cout << std::endl;

	// Mixed tests - should not compile
	// const Animal* a = new WrongCat();
	// const WrongAnimal* wa = new Cat();

	return 0;
}
