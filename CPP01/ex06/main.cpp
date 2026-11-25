#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl a;

	if (argc < 2)
	{
		a.complain("");
		return (0);
	}
	if (argc > 2)
		std::cout << "Filtering only with first arg: " << argv[1];
    a.complain(argv[1]);
}