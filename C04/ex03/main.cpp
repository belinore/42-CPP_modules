#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

//virtual enables polymorphism.
//= 0 enforces a contract that derived classes must implement this method

//Every class exists either to define a contract, share behavior, or own resources.

int main()
{
	IMateriaSource* src = new MateriaSource(); //MateriaSource implements IMateriaSource
	src->learnMateria(new Ice());//learnMateria takes AMateria pointers
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");//Character implements ICharacter
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}