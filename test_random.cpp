#include <ctime>
#include <cstdlib>
#include <iostream>

int main()
{
	int num;
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	srand(time(NULL));
	for (int i = 0; i < 1000000; i++)
	{
		num = rand() % 3;
		switch (num)
		{
			case 0: count0++; break;
			case 1: count1++; break;
			case 2: count2++; break;
		}
	}
	std::cout << "Count of 0: " << count0 << '\n';
	std::cout << "Count of 1: " << count1 << '\n';
	std::cout << "Count of 2: " << count2 << '\n';
}