#include "Harl.hpp"

int main(void)
{
    Harl a;
    a.complain("error");
	a.complain("warning");
	a.complain("debug");
	a.complain("info");
	a.complain("warning");
	a.complain("debug");
	a.complain("error");
	a.complain("info");
}