#define CYAN "\033[36m"
#define RESET "\033[0m"
#include "Span.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>

void gen_random_nbrs_vector(std::vector<int> &v, size_t size, int max_value)
{
	for (size_t i = 0; i < size; i++)
		v.push_back(rand() % max_value);
}

void gen_nbrs_fibonacci(std::vector<int> &v, size_t size)
{
	size_t n = 0;
	v.push_back(n);
	size_t n1 = 1;
	v.push_back(n1);
	size_t value;
	for (size_t i = 2; i < size; i++)
	{
		value = n + n1;
		v.push_back(value);
		n = n1;
		n1 = value;
	}
}

void gen_nbrs_simple(std::vector<int> &v, size_t max)
{
	for (size_t i = 1; i < max; i *= 2)
	{
		v.push_back(i);
	}
}

void print_vector_all(std::vector<int> &v, std::string prefix)
{
    if (!prefix.empty())
		std::cout << prefix;
	std::vector<int>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

int main()
{
	srand(time(NULL));
	std::vector<int> v;
	gen_random_nbrs_vector(v, 10, 20);
	print_vector_all(v, "Vector: ");
	Span span(100);
	//span.addNumbers(v);
	span.addNumber2(v.begin(), v.end());
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;

	std::vector<int> fib;
	gen_nbrs_fibonacci(fib, 20);
	print_vector_all(fib, "Fib: ");
	Span spanfib(20);
	//spanfib.addNumbers(fib);
	spanfib.addNumber2(fib.begin(), fib.end());
	std::cout << "Shortest :" << spanfib.shortestSpan() << std::endl;
	std::cout << "Longest :" << spanfib.longestSpan() << std::endl;

	std::vector<int>simple;
	gen_nbrs_simple(simple, 100);
	print_vector_all(simple, "Simple: ");
	Span spanvect(7);
	//spanvect.addNumbers(simple);
	spanvect.addNumber2(simple.begin(), simple.end());
	std::cout << "Shortest :" << spanvect.shortestSpan() << std::endl;
	std::cout << "Longest :" << spanvect.longestSpan() << std::endl;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }