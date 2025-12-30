#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>

//copy constructor - creates a new object as a copy of an existing object
//copy assignment operator - assigns the values from one existing object to another existing object.
//const at start means the return value is const, at end means the method does not modify the object
class ClapTrap
{
	public:
	ClapTrap(const std::string &name); //constructor
	ClapTrap(const std::string &name, int hitPoints, int energyPoints, int attackDamage); //parameterized constructor
	~ClapTrap(); //destructor
	ClapTrap(const ClapTrap &other); //copy constructor
	ClapTrap &operator=(const ClapTrap &other); //copy assignment operator
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName() const;
	unsigned int getHitPoints() const;
	unsigned int getAttackDamage() const;

	private:
	std::string	_name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

};

#endif