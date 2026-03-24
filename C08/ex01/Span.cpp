#include "Span.hpp"
#include <iostream>
#include <limits>
#include <algorithm>

Span::Span(unsigned int N) : _maxSize(N)
{
	std::cout << "Constructed: Span" << "\n";
}

Span::~Span()
{
	std::cout << "Destructed: Span" << "\n";
}

Span::Span(const Span &other)
{
	Span(other._maxSize);
	std::cout << "Copy Constructed: Span" << "\n";
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_array = other._array;
	}
	return (*this);
}

void Span::addNumber(int N)
{
	if (_array.size() < _maxSize)
	{
		_array.push_back(N);
	}
	else
	{
		std::cout << "Handle exception\n";
	}
}

unsigned int Span::shortestSpan()
{
	if (_array.size() == 0)
		return (0);//HANDLE
	std::vector<int> sorted = _array;
	std::sort(sorted.begin(), sorted.end());
	print_vector_all(sorted, "Sorted vector: ");
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	std::vector<int>::iterator it = sorted.begin();
	unsigned int span;
	for (; it + 1 != sorted.end(); it++)
	{
		span = *(it + 1) - *it;
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

unsigned int Span::longestSpan()
{
	if (_array.size() == 0)
		return (0);//HANDLE
	std::vector<int>::iterator min = std::min_element(_array.begin(), _array.end());
	std::vector<int>::iterator max = std::max_element(_array.begin(), _array.end());
	return (*max - *min);
}

void Span::addNumbers(std::vector<int> &v)
{
	std::vector<int>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		addNumber(*it);
	}
}

