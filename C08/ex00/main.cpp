//#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <queue>


void print_vector_all(std::vector<int> &v)
{
	std::vector<int>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

void print_vector(std::vector<int> &v, size_t start, size_t size)
{
	try
	{
		for (size_t i = start; i < size; i++)
			std::cout << v.at(i) << " ";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
}

void generate_random_numbers(std::vector<int> &v, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		v.push_back(rand() % 100);
	}

}

int main()
{
	srand(time(NULL));
	//Vector
	std::vector<int> v;
	if (v.empty())
		std::cout << "Empty vector created...\n";
	v.push_back(1);
	v.push_back(2);
	std::cout << v.at(0) << " = " << v.front() << " / "
	          << v.at(1) << " = " << v.back() << "\n";
	std::cout << "Size = " << v.size() << " Max size: "
			  << v.max_size() << "\n"; 
	for (int i = 3; i < 10; i++)
		v.push_back(i);
	print_vector(v, 0, v.size());
	print_vector_all(v);
	std::vector<int> v2;
	generate_random_numbers(v2, 20);
	print_vector_all(v2);

	//Queue
	//std::queue<int> q;
	
	// std::c
}
