#include "ScalarConverter.hpp"
#include "test_utils.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string value = argv[1];
		ScalarConverter::convert(value);
	}
	else
	{
		std::cerr << "Error: expected 2 args ./convert [value]\n";
		if (argc == 1)
		{
			if (get_yesno_input("Run default tests? y/n"))
				test_examples();
		}
	}
	return (0);
}

