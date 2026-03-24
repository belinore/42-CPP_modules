#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <string>

class Span
{
    private:
    unsigned int _maxSize;
	std::vector<int> _array;

    public:
    Span(unsigned int N);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);

    void addNumber(int N);
	void addNumbers(std::vector<int> &v);
    unsigned int shortestSpan();
    unsigned int longestSpan();

	template <typename I>
	void addNumber2(I begin, I end);
};

template <typename I>
void Span::addNumber2(I begin, I end)
{
	for (I it = begin; it != end; it++)
	{
		addNumber(*it);
	}
}

void print_vector_all(std::vector<int> &v, std::string prefix = "");

#endif