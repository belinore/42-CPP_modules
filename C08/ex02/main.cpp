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
	std::cout << CYAN << "Test 1\n" << RESET;
	test_from_subject();

	std::cout << CYAN << "Test 2\n" << RESET;
}