#ifndef TESTS_HPP
#define TESTS_HPP
#include <string>

#define CYAN "\033[36m"
#define RESET "\033[0m"

bool get_yesno_input(const std::string &prompt);
void test_examples();

#endif
