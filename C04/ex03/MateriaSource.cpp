#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _count(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
	std::cout << "Constructed: MateriaSource" <<  std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "Destructed: MateriaSource" <<  std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) : _count(other._count)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
	std::cout << "Copy Constructed: MateriaSource" <<  std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		_count = other._count;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	std::cout << "Copy Assigned: MateriaSource" <<  std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (_count < 4 && materia)
	{
		_inventory[_count] = materia;
		_count++;
		std::cout << "Learned Materia: " << materia->getType() << std::endl;
	}
	else
	{
		std::cout << "Cannot learn more Materia!" << std::endl;
		delete materia;
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < _count; i++)
	{
		if (_inventory[i]->getType() == type)
		{
			std::cout << "Created Materia: " << type << std::endl;
			return (_inventory[i]->clone());
		}
	}
	std::cout << "Materia of type " << type << " not found!" << std::endl;
	return (nullptr);
}