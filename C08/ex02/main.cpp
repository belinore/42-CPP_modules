/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 09:47:15 by belinore          #+#    #+#             */
/*   Updated: 2026/04/15 14:41:20 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#define CYAN "\033[36m"
#define RESET "\033[0m"

void test_from_subject()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Stack:\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

int main(void)
{
	std::cout << CYAN << "Test 0 - subject\n" << RESET;
	test_from_subject();
	std::cout << CYAN << "Test 1 - standard\n" << RESET;
	MutantStack<char> mstack;
	for (char c = 'a'; c <= 'z'; c++)
	{
		mstack.push(c);
	}
	MutantStack<char>::iterator it = mstack.begin();
	MutantStack<char>::iterator itEnd = mstack.end();
	while (it != itEnd)
	{
		std::cout << *it;
		it++;
	}
	std::cout << CYAN << "\nTest 2 - reverse\n" << RESET;
	MutantStack<char>::reverse_iterator it1 = mstack.rbegin();
	MutantStack<char>::reverse_iterator itEnd1 = mstack.rend();
	while (it1 != itEnd1)
	{
		std::cout << *it1;
		it1++;
	}
	std::cout << CYAN << "\nTest 3 - const\n" << RESET;
	const MutantStack<char> cstack = mstack;
	MutantStack<char>::const_iterator it2 = cstack.begin();
	MutantStack<char>::const_iterator itEnd2 = cstack.end();
	while (it2 != itEnd2)
	{
		std::cout << *it2;
		it2++;
	}
	std::cout << CYAN << "\nTest 4 - const reverse\n" << RESET;
	const MutantStack<char> rcstack = cstack;
	MutantStack<char>::const_reverse_iterator it3 = cstack.rbegin();
	MutantStack<char>::const_reverse_iterator itEnd3 = cstack.rend();
	while (it3 != itEnd3)
	{
		std::cout << *it3;
		it3++;
	}
	std::cout << std::endl;
}
