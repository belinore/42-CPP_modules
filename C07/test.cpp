#include "whatever.hpp"
#include <iostream>

void swap(void **param1, void **param2)
{
	void *temp;

	temp = *param1;
	*param1 = *param2;
	*param2 = temp;
}

int main()
{
	int a = 1;
	int b = 34;
	int *ai = &a;
	int *bi = &b;
	std::cout << "a = " << *ai << "\nb = " << *bi << "\n";
	void *ap = ai;
	void *bp = bi;
	swap(&ap, &bp);
	ai = static_cast<int*>(ap);
	bi = static_cast<int*>(bp);
	std::cout << "a = " << *ai << "\nb = " << *bi << "\n";
}