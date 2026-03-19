/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:09:58 by belinore          #+#    #+#             */
/*   Updated: 2026/03/19 17:09:59 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base* generate(void)
{
	switch (rand() % 3)
	{
		case 0: return (new A());
		case 1: return (new B());
		case 2: return (new C());
		default: return (NULL);
	}
}
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void identify(Base& p)
{
	try
	{
		A &test = dynamic_cast<A&>(p);
		(void)test;
		std::cout << "A\n";
		return ;
	} catch(...){}
	try
	{
		B &test = dynamic_cast<B&>(p);
		(void)test;
		std::cout << "B\n";
		return ;
	} catch(...){}
	try
	{
		C &test = dynamic_cast<C&>(p);
		(void)test;
		std::cout << "C\n";
		return ;
	} catch(...){}
}

int main()
{
	srand(time(NULL));
	std::cout << "Generating a random instance of A, B, or C...\n";
	Base *ptr = generate();
	std::cout << "Type of the instance using pointer:\n";
	identify(ptr);
	std::cout << "Type of the instance using reference:\n";
	identify(*ptr);
	delete ptr;
}