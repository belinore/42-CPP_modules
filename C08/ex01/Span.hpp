/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 09:38:56 by belinore          #+#    #+#             */
/*   Updated: 2026/04/15 09:45:23 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <string>

#define CYAN "\033[36m"
#define RESET "\033[0m"
#define RANDOM_MAX 50

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
    unsigned int shortestSpan();
    unsigned int longestSpan();

	template <typename I>
	void addNumber(I begin, I end);
};

template <typename I>
void Span::addNumber(I begin, I end)
{
	for (I it = begin; it != end; it++)
	{
		addNumber(*it);
	}
}

template <typename T>
void print_container(T &container, std::string prefix)
{
    if (!prefix.empty())
        std::cout << prefix;
    typename T::iterator it = container.begin();
    for (; it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
}

#endif
