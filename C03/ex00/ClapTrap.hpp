#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>

class ClapTrap
{
	public:
	ClapTrap(const std::string &name); //constructor
	~ClapTrap(); //destructor
	ClapTrap(const ClapTrap &other); //copy constructor
	ClapTrap &operator=(const ClapTrap &other); //copy assignment operator

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	private:
	std::string	_name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

};

#endif