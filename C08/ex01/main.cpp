#define CYAN "\033[36m"
#define RESET "\033[0m"
#define RANDOM_MAX 50
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

template <typename T>
void gen_random_nbrs(T &c, size_t size)
{
	for (size_t i = 0; i < size; i++)
		c.push_back(rand() % RANDOM_MAX);
}

void gen_random_nbrs_vector(std::vector<int> &v, size_t size)
{
	gen_random_nbrs(v, size);
}

// void gen_random_nbrs_list(std::list<int> &l, size_t size, int max_value)
// {
//     for (size_t i = 0; i < size; i++)
//         l.push_back(rand() % max_value);
// }

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

void gen_nbrs_powers2(std::vector<int> &v, size_t size)
{
    size_t n = 1;
	for (size_t i = 0; i < size; i++)
	{
		v.push_back(n);
        n *= 2;
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

template <typename T>
void print_container_all(T &container, std::string prefix)
{
    if (!prefix.empty())
        std::cout << prefix;
    typename T::iterator it = container.begin();
    for (; it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
}

template <typename F, typename C>
void test_span(F generator, std::string name, C v, int size = 10)
{
    if (size < 0)
    {
        std::cerr << "Invalid size for " << name << ": " << size << "\n\n";
        return;
    }
    size_t sizet = static_cast<size_t>(size);
    generator(v, sizet);
    print_container_all(v, name + ": ");
    Span span(sizet);
    try
    {
        span.addNumber(v.begin(), v.end());
        unsigned int shortest = span.shortestSpan();
        std::cout << "Shortest span: " << shortest << "\n";
        std::cout << "Longest span: " << span.longestSpan() << "\n\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n\n";
    }    
}

int main()
{
    test_span(gen_nbrs_powers2, "PowersOf2 Vector", std::vector<int>());
    test_span(gen_nbrs_fibonacci, "Fibonacci Vector", std::vector<int>(), 20);
    srand(time(NULL));
    test_span(gen_random_nbrs_vector, "Random Vector", std::vector<int>(), 20);
    test_span(gen_random_nbrs_vector, "Random Vector2", std::vector<int>(), 100);
    test_span(gen_random_nbrs_vector, "1 size Vector", std::vector<int>(), 1);
    test_span(gen_random_nbrs_vector, "0 size Vector", std::vector<int>(), 0);
    test_span(gen_random_nbrs_vector, "Neg Size Vect", std::vector<int>(), -1);

    test_span(gen_random_nbrs<std::list<int> >, "List", std::list<int>(), 10);


    //q: which other containers have iterators that can be used with the addNumber template function?
    //a: Any container that supports iterators can be used with the addNumber template function. This includes:
    // - std::list
    // - std::deque
    // - std::set
    // - std::map (but you would need to use the value_type of the map, which is a pair of key and value)
    // - std::unordered_set
    // - std::unordered_map (but you would need to use the value_type of the unordered_map, which is a pair of key and value)
    // - std::vector (as already used in the tests)
    // The addNumber template function is designed to work with any container that provides begin() and end() iterators, so as long as the container supports these, it can be used to add numbers to the Span class.
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