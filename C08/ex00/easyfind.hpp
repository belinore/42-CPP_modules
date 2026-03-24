#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <string>

#define CYAN "\033[36m"
#define RESET "\033[0m"

template <typename T>
typename T::iterator easyfind(T& container, int to_find);

template <typename T>
void test_easyfind(T &container, int to_find, std::string container_name);

template <typename T>
void print_container_all(T &container, std::string prefix);

template <typename T>
void print_container_from_iterator(T &container, typename T::iterator it, std::string prefix);

#include "easyfind.tpp"

#endif