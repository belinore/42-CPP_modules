/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:50:24 by belinore          #+#    #+#             */
/*   Updated: 2026/02/09 14:31:28 by belinore         ###   ########.fr       */
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

	std::cout << "\n[8 - WrongCat test]\n";
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "wrongCat Type: " << wrongCat->getType() << "\n";
	std::cout << "wrongCat Sound: ";
	wrongCat->makeSound();
	//outputs the WrongAnimal sound
	delete wrongCat;
	std::cout << std::endl;
	// Mixed tests - should not compile
	// const Animal* a = new WrongCat();
	// const WrongAnimal* wa = new Cat();
	return 0;
}
