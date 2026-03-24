#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
    private:
    unsigned int _N;

    public:
    Span(unsigned int);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);

    void addNumber(unsigned int N);
    unsigned int shortestSpan();
    unsigned int longestSpan();
};

#endif