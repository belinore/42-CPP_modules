#define CYAN "\033[36m"
#define RESET "\033[0m"
#define RANDOM_MAX 50
#include "Span.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
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

void gen_nbrs_powers2(std::vector<int> &v, size_t size)
{
    size_t n = 1;
	for (size_t i = 0; i < size; i++)
	{
		v.push_back(n);
        n *= 2;
	}
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
    print_container(v, name + ": ");
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

    srand(time(NULL));
    test_span(gen_random_nbrs_vector, "Random Vector", std::vector<int>(), 20);
    test_span(gen_random_nbrs_vector, "1 size Vector", std::vector<int>(), 1);
    test_span(gen_random_nbrs_vector, "0 size Vector", std::vector<int>(), 0);
    test_span(gen_random_nbrs_vector, "Neg Size Vect", std::vector<int>(), -1);

    test_span(gen_random_nbrs<std::list<int> >, "List", std::list<int>());
    test_span(gen_random_nbrs<std::deque<int> >, "Deque", std::deque<int>());
}
