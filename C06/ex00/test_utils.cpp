#include "test_utils.hpp"
#include "ScalarConverter.hpp"
#include <iostream>

bool get_yesno_input(const std::string &prompt)
{
	std::string input;
	std::cout << prompt << std::endl;
	while (std::getline(std::cin,input))
	{
		if (input == "y" || input == "yes" || input == "Y")
			return (true);
		else if (input == "n" || input == "no" || input == "N")
			return (false);
		else
			std::cout << "Please enter y/n\n";
	}
	return (false);
}

void test_examples()
{
	std::cout << CYAN << "Input: 0\n" << RESET;
	ScalarConverter::convert("0");
	std::cout << CYAN << "\nInput: nan\n" << RESET;
	ScalarConverter::convert("nan");
	std::cout << CYAN << "\nInput: 42.0f\n" << RESET;
	ScalarConverter::convert("42.0f");
	std::cout << CYAN << "\nInput: nanf\n" << RESET;
	ScalarConverter::convert("nanf");
	std::cout << CYAN << "\nInput: 42.0\n" << RESET;
	ScalarConverter::convert("42.0");
	std::cout << CYAN << "\nInput: a\n" << RESET;
	ScalarConverter::convert("a");
	std::cout << CYAN << "\nInput: 0.0f\n" << RESET;
	ScalarConverter::convert("0.0f");
	std::cout << CYAN << "\nInput: 0.0\n" << RESET;
	ScalarConverter::convert("0.0");
	std::cout << CYAN << "\nInput: 127\n" << RESET;
	ScalarConverter::convert("127");
	std::cout << CYAN << "\nInput: 128\n" << RESET;
	ScalarConverter::convert("128");
	std::cout << CYAN << "\nInput: -5\n" << RESET;
	ScalarConverter::convert("-5");
	std::cout << CYAN << "\nInput: 2147483647\n" << RESET;
	ScalarConverter::convert("2147483647");
	std::cout << CYAN << "\nInput: 2147483648\n" << RESET;
	ScalarConverter::convert("2147483648");
	std::cout << CYAN << "\nInput: -2147483648\n" << RESET;
	ScalarConverter::convert("-2147483648");
	std::cout << CYAN << "\nInput: -2147483649\n" << RESET;
	ScalarConverter::convert("-2147483649");
	std::cout << CYAN << "\nInput: inf\n" << RESET;
	ScalarConverter::convert("inf");
	std::cout << CYAN << "\nInput: -inff\n" << RESET;
	ScalarConverter::convert("-inff");
	std::cout << CYAN << "\nInput: -inf\n" << RESET;
	ScalarConverter::convert("-inf");
	std::cout << CYAN << "\nInput: 1e40\n" << RESET;
	ScalarConverter::convert("1e40");
}
